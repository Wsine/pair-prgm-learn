# pair-prgm-learn

This is the repository for the paper "Toward AI-facilitate Learning Cycle in Integration Course through Pair Programming with AI Agents".

## How to use

The dependencies are managed with [PDM](https://pdm-project.org/latest/). You can install the locked dependencies easily by a single command.

```bash
$ pdm sync
```

Next, there are four confidential environment variables needed to prepare.

- `HKU_API_KEY`
  - for accessing the Azure ChatGPT service
- `MODEL_NAME`
  - ChatGPT model deployment name
- `SYSTEM_PROMPT`
  - the system prompt for the chat conversation
- `MOSS_USER_ID`
  - the user id of your MOSS account

You can also save the environment variables into a `.env` file. PDM will automatically read them when executing the program.

Then, run the individual code, e.g.,

```bash
$ pdm run python generate_scaffold.py
```

## Results

You may also check the reported results under the `moss_report` folder.

