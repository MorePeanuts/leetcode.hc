# LeetCode

This repository is the hc pack `leetcode`: problems in the format of
[handcoding (hc)](https://github.com/MorePeanuts/handcoding), which judges
them locally. A checkout of it is an hc authoring workspace: hc run anywhere
in it works on this pack, and `hc fetch`, `hc new` and `hc gen` add and
change problems in `problems/`.

- The problem protocol, the format of `pack.yaml` and of every problem, is
  defined by MorePeanuts/handcoding: `hc docs protocol` prints it, and
  `hc docs protocol <section>` one section of it.
- A problem lands only when `hc pack check` passes, which is what CI runs.
- The languages of the statements, `locales` in `pack.yaml`, are the
  author's decision. Never translate a statement or a title: write only
  what you are asked to, and report the locales a problem lacks.
- If a problem cannot be expressed in the protocol, do not work around it:
  open an issue at https://github.com/MorePeanuts/handcoding/issues that says
  what is missing, and leave the problem out until the protocol has it.

<!-- Your own notes for agents go here. hc rewrites only the block between its markers below. -->

## Pack conventions

CONTRIBUTING.md holds this pack's rules on top of hc's skills; follow it.
Where they overlap, it narrows the skills, never loosens them:

- Commit messages are Conventional Commits, one problem per commit:
  `feat: add 0001-two-sum`, with its group changes in the same commit;
  `fix(0146-lru-cache): …` for a fix to a problem.
- Fetch with `hc fetch --site cn <slug>`, which writes both locales.
- Bump `version`, tag and release only when asked, as CONTRIBUTING.md says.

<!-- hc:begin -->
## hc skills

This is a handcoding (hc) workspace. Before you work on a task one of these
skills covers, read its SKILL.md and follow it:

- `hc-cases`: Decide how an hc (handcoding) problem is judged and write its test cases. Use when generating or fixing the test cases (cases.jsonl) of a problem in an hc workspace, choosing its judge rule (judge.compare in problem.yaml), writing or fixing a reference solution (reference/solution.py or .go), writing a checker (checker.py), or generators of large inputs (generator.py); `hc gen` and `hc fix` use it. For the problem's definition itself (signature, structure inputs, statement, templates), use hc-problem instead. Read `.agents/skills/hc-cases/SKILL.md`.
- `hc-pack`: Maintain an hc (handcoding) pack as a whole, in a pack checkout (a directory with pack.yaml). Use when landing a finished problem in the pack, placing problems in groups or changing the groups, removing a problem, moving the pack to a new protocol version or bumping the hc version its CI pins, releasing a new version of the pack, when asked to rename a problem's slug or the pack, or when the protocol cannot express a problem. For writing or fixing one problem use hc-problem, and for its judge rule, references and test cases hc-cases. Read `.agents/skills/hc-pack/SKILL.md`.
- `hc-problem`: Write or fix the definition of an hc (handcoding) problem, what it is rather than how it is judged, that is its directory and identity, its problem.yaml signature (kind, parameters, structure inputs such as hidden, cycle, join, ref, copy and returns_ref, returns_copy, LeetCode's Node types, round_trip, in-place judge.output), its description.md and its templates. Use when writing a new problem in an hc workspace (`hc new`), checking a problem fetched with `hc fetch`, or fixing a problem whose signature, statement or templates are wrong. For the judge rule (judge.compare), reference solutions, checkers and test cases, use hc-cases instead. Read `.agents/skills/hc-problem/SKILL.md`.

Keep throwaway files (scripts, scratch data) in .hc/scratch/: .hc/ is hc's
own directory, never part of a pack. Delete them when you are done.

hc rewrites this block when it installs skills; write your own notes outside it.
<!-- hc:end -->
