# Contributing

Thanks for your interest in leetcode.hc. This repository is an [hc](https://github.com/MorePeanuts/handcoding) pack: the format of `pack.yaml` and of every problem is hc's problem protocol (`hc docs protocol`), and [Writing packs](https://github.com/MorePeanuts/handcoding/blob/main/docs/packs.md) is the guide to working on one. This file holds the rules of this pack on top of them.

## Issues first

Open an issue before starting on anything non-trivial. Problems are added in batches, each an issue with a checklist of problems, collected in a milestone such as `neetcode150`; problems not planned yet wait in `Backlog`. A wrong statement, case, reference or judge rule is a `problem-bug` issue.

## Adding problems

You need hc at the version CI pins (`.github/workflows/check.yml`), Go and Python 3.10+.

```sh
hc fetch --site cn two-sum     # statement in English and Chinese, signature, templates, examples
hc gen two-sum                 # an agent writes the references, the cases and the judge rule
hc validate two-sum --run      # every reference passes every case
hc pack check                  # the whole pack, as CI checks it
```

- **What lands.** A problem lands only when `hc pack check` passes: it is ready (`judge.compare` is set), has Go and Python references, and has a statement and a title in every locale of `pack.yaml` (`en` and `zh-CN`). `hc fetch --site cn` writes both; nobody translates one, so a problem LeetCode lacks a statement for stays out. No premium problems, and no LeetCode test data beyond the statements' examples.
- **Groups.** Add the slug to every topic group of `pack.yaml` it fits, in the same commit as the problem. Group `name`s are what users filter by, so change a group's `title` or order rather than its `name`.
- **Identity.** `slug` and `id` are LeetCode's, and are frozen once published: never rename a slug or a directory, never change an `id`, never reuse the slug of a removed problem. When a problem has to change that much, it becomes a new problem with a new slug.
- **Cases.** Aim for 30 to 40 cases per problem, fewer for a simple one and more for a tricky one. Small inputs are stored in `cases.jsonl`, where a reader can see them; a stored case over 100 KB fails `hc pack check`. Large inputs are generated cases: functions of the problem's `generator.py` (`hc docs protocol generators`), a few near the constraint limits. Stored data stays in the history that `hc pack install` clones, so never commit large inputs, even in a commit that a later one removes.
- **Protocol gaps.** If the protocol cannot express a problem, do not work around it: open an issue at [handcoding](https://github.com/MorePeanuts/handcoding/issues) saying what is missing, label the problem's issue here `blocked:upstream` with a link to it, and leave the problem out.
- Commit only the pack's files: never `solutions/`, `.hc/`, `hc.yaml` or `pyrightconfig.json` (`.gitignore` keeps them out). Throwaway scripts go in `.hc/scratch/`.
- **Review.** A pack is code that runs on its users' machines: review every `reference/`, `checker.py` and `generator.py` a pull request changes, as `hc pack install` asks its users to.

## Branches and pull requests

`main` is always releasable: on every commit `hc pack check` passes. Work happens on short-lived branches merged through a pull request, then deleted. Typos and wording in the README or this file may go to `main` directly.

Name branches `<type>/<issue>-<summary>`: `feat/3-arrays-hashing`, `fix/12-lru-cache-cases`, `chore/hc-v0.1.0`.

Commit messages and PR titles follow [Conventional Commits](https://www.conventionalcommits.org/):

| Change | Message |
|---|---|
| A new problem, with its group changes | `feat: add 0001-two-sum` |
| New or changed groups | `feat(groups): …` |
| A fix to a problem's statement, cases, references or judge rule | `fix(0146-lru-cache): …` |
| Bumping the pinned hc | `chore: bump hc to v0.1.0` |
| README, this file | `docs: …` |
| A breaking change ([below](#versions-and-releases)) | `!` after the type, `feat!: …`, and a `BREAKING CHANGE:` footer |

- **One problem per commit**, so that the history of a problem is the history of its commits.
- **A single change** (one problem, one fix) is a PR that is **squash merged**: its title becomes the commit on `main`.
- **A batch of problems** is one PR with one commit per problem, each conventionally titled and passing `hc pack check` on its own, and is **rebase merged**. CI checks only the PR's last commit, so run `hc pack check` before each commit.
- Merge commits are disabled. Link the issue the PR closes (`Closes #N`, or `Part of #N` for part of a batch).
- Label the PR: `problems` for new problems, `problem-bug` for fixes to them, `breaking` for a breaking change. The release notes are grouped by these labels.

## Versions and releases

Versions are [SemVer](https://semver.org/): a tag `vX.Y.Z` on `main`, and `version: X.Y.Z` in `pack.yaml` on the tagged commit. Installs are pinned by commit, so the version tells users what changed.

When to release is the maintainer's call: typically when a batch issue is closed, or when fixes are worth shipping without waiting for the next batch. Which number to bump follows from what the release contains:

| The release contains | Bump |
|---|---|
| Any breaking change: a removed problem, a changed slug, a signature changed so that saved solutions break, a removed language, a higher `protocol` | Major (minor before 1.0.0) |
| At least one new problem, or a new group | Minor |
| Only fixes: statements, cases, references, judge rules, group titles or order | Patch |

- Fixes made while adding problems ship with the next minor release; a patch release is for fixes alone.
- The pack stays on 0.x while hc is in pre-release, and becomes 1.0.0 when hc v0.1.0 is released. From then on a breaking change bumps the major version; before, it bumps the minor one, and the release notes mark it **BREAKING**.
- There are no pre-release versions and no maintenance branches: every release is on `main`.

To release:

1. Commit `chore: release vX.Y.Z`, which changes only `version` in `pack.yaml`, and push it to `main`.
2. Once its CI passes, tag it: `git tag vX.Y.Z && git push origin vX.Y.Z`. Never move or delete a published tag: installs that follow it would not see the change.
3. Create the GitHub release: `gh release create vX.Y.Z --generate-notes`, then edit the notes: the problems added, fixed and removed, every breaking change with what users should do, and the oldest hc that reads the pack. The release is the only place release notes are kept.

## Bumping hc

CI installs a pinned hc, and checks that the committed skills (`.claude/skills/`, `.agents/skills/`, hc's block of `AGENTS.md`) are exactly that hc's. Bump the pin when a newer hc brings something the pack wants: a fix to its checks, or a feature of a newer protocol.

1. Install the new hc locally, and read what changed: its release notes and `hc docs protocol protocol-versions`.
2. Change the version in `.github/workflows/check.yml`.
3. Run `hc skill install`, and review the diff of the skills: agents follow the new versions from now on.
4. Run `hc pack check`.
5. Land it as one PR of its own (`chore: bump hc to vX`, label `hc-bump`), separate from problems.

Bumping hc does not change `protocol` in `pack.yaml`. Raise that only when a problem needs a feature the newer protocol introduced: hc versions that do not read it then refuse the pack, so it is a breaking change.
