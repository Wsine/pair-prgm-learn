import os
import time

from dotenv import load_dotenv
from openai import AzureOpenAI
from jinja2.nativetypes import NativeTemplate
import marko


load_dotenv()

client = AzureOpenAI(
    api_key=os.environ['HKU_API_KEY'],
    api_version='2023-12-01-preview',
    azure_endpoint='https://api.hku.hk'
)

# create a new folder called scaffold
if not os.path.exists('completement'):
    os.mkdir('completement')
# read the prompt template
with open('complete.prompt.jinia', 'r') as f:
    prompt_template = NativeTemplate(f.read())
# walk throught the files under the example folder
for file in os.listdir('scaffold'):
    if not os.path.exists('completement/' + file):
        print('handling file: ' + file)
        # read file from example file
        with open('scaffold/' + file, 'r') as f:
            scaffold_code = f.read()
        user_prompt = prompt_template.render(scaffold_code=scaffold_code)
        # generate completement code
        completion = client.chat.completions.create(
            model=os.environ['MODEL_NAME'],
            messages=[
                {'role': 'system', 'content': os.environ['SYSTEM_PROMPT']},
                {'role': 'user', 'content': user_prompt}
            ]
        )
        generated_content = completion.choices[0].message.content
        print(generated_content)
        # extract the generated code from the markdown response
        try:
            md_doc = marko.parse(generated_content) # pyright: ignore
            md_code, *_ = [
                node for node in md_doc.children
                if isinstance(node, marko.block.FencedCode)
            ]
            code = md_code.children[0].children  # pyright: ignore
            # write the scaffold code to the scaffold folder
            with open('completement/' + file, 'w') as f:
                f.write(code)
        except:
            print('\tError handling file: ' + file)
        # sleep for 1 minute to avoid rate limit
        print('sleeping for 1 minute...')
        time.sleep(60)
print('done')
