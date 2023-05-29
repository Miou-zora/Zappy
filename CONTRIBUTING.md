# Contribution guidelines

Thank you for considering contributing to our Zappy project!

These guidelines are meant for new contributors, regardless of their level
of proficiency; following them allows the maintainers our Zappy project to
more effectively evaluate your contribution, and provide prompt feedback to
you. Additionally, by following these guidelines you clearly communicate
that you respect the time and effort that the people developing Zappy put into
managing the project.

#### Langage: English

All interactions should be in English, to allow everyone to understand and participate.

### Description of the project

The goal of this project is to create a network game where several teams confront on a tiles map containing
resources.

The winning team is the first one where at least 6 players who reach the maximum elevation.

## Table of Contents

- [Documentation](#documentation)
- [How to launch the project](#how-to-launch-the-project)
  - [Dependencies](#dependencies)
  - [Compilation](#compilation)
  - [Execution](#execution)
- [How to report a bug](#how-to-report-a-bug)
- [How to suggest a feature or enhancement](#how-to-suggest-a-feature-or-enhancement)
- [Where can I ask for help?](#where-can-i-ask-for-help)
- [Coding style](#coding-style)
- [Commit format](#commit-format)
- [Labels](#labels)
- [Branches](#branches)
- [Pull Requests](#pull-requests)
- [Milestone](#milestone)
- [Testing Policies](#testing-policies)

## Documentation

There is no documentation for the moment. You can find the subject of the project in the root of the repository. But you can maybe find some documentation in the code.

## How to launch the project

### Dependencies
To launch the project, you need to install the following dependencies:
- [CMake](https://cmake.org/)
- [Make](https://www.gnu.org/software/make/)
- [OpenGL](https://www.opengl.org/) or [SFML](https://www.sfml-dev.org/)
- [Python 3.10.6](https://www.python.org/downloads/release/python-3106/)

### Compilation

To compile the project, you need to run the following commands at the root of the repository:
```bash
make zappy_server
make zappy_ai
make zappy_gui
```

To clean the project, you need to run the following commands at the root of the repository:
```bash
make fclean
```

### Execution

To launch the server, there is help for it:
```
USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb
-f freq
  port      is the port number
  width     is the width of the world
  height    is the height of the world
  nameX     is the name of the team X
  clientsNb is the number of authorized clients per team
  freq      is the reciprocal of time unit for execution of actions
```

To launch the GUI, there is help for it:
```
USAGE: ./zappy_ai -p port -h machine
  port      is the port number
  machine   is the name of the machine; localhost by default
```

To launch the AI, there is help for it:
```
USAGE: ./zappy_ai -p port -n name -h machine
  port      is the port number
  name      is the name of the team
  machine   is the name of the machine; localhost by default
```

## How to report a bug

If you find a bug, you can open an issue on the repository. You need to describe the bug and how to reproduce it.

## How to suggest a feature or enhancement

If you want to suggest a feature or enhancement, you can open an issue on the repository. You need to describe the feature or enhancement.

## Where can I ask for help?

You can ask for help to [developpers team](#Contributors) or on the issue/PR.

(When interacting with us, please be human being)
## Coding style

We use Epitech coding style for C (look at the root of the repository). For C++, we try to use the same coding style. "Try" because we are not perfect. And for python we don't have a coding style for the moment but please don't be a dick and think a bit when writting code.

## Commit format

In the project, we use [Angular Commit Convention](https://www.conventionalcommits.org/en/v1.0.0-beta.4/)

## Labels

Each labels must be the type of the Issue BUT if you do a Pull Request you must use `Ready` or `Not Ready` depending of the state of the Pull Request.

## Branch

### Namming

Branch should have an automatic namming due to branch creation via issues. But if you create a branch from nothing you must use this template:

[_branch-name_]_branch-description_

## Pull Requests (PR)

### Namming

If you create a PR, you must use this template:

[_pr name_] _pr description_

(In most of the case, you can reuse issue name)

### Process

#### Code review
For each PR we'll have a code review, the PR must be approved by 2 developper of the [developpers team](#Contributors).

#### PR Stability
Look at the [**Testing Policies**](#testing-policies)

#### Miscellaneous

Don't forget to add `Ready` or `Not Ready` label to PR.

Don't add to Zappy github project except if the PR it.

Don't add to any Milestone of the project. If you doubt, ask to [developpers team](#Contributors).

You can speak in French or English in the PR.

## Milestone

Milestone are used to organize the project. Each milestone must have a description and a due date. A milestone should be linked to an issue or a PR. A milestone should be linked to a set of functionnalities that makes the project works or a set of functionnalities that makes the project cohérent.

### Namming

If you create a milestone, you must use this template:

[_milestone-name_]_milestone-description_

## Testing Policies

### Unit tests (Server)

Library: [Criterion](https://github.com/Snaipe/Criterion)

We want 50% coverage (if not for technical reason like testing a malloc or getline you'll have to explain why it's not possible)

### Unit tests (AI, GUI)

Library:
For AI you can use [pytest](https://docs.pytest.org/en/6.2.x/) and for GUI you can use [Criterion](https://github.com/Snaipe/Criterion)

Please do unit tests if you can. We don't have a coverage goal for the moment.

### Functional tests

We don't force you to do functional tests but if you can do it, it's better. For GUI you can make User Acceptance Tests (UAT).

For AI and server, you can make a script that launch Server and AI and check if the AI is working correctly with server.

### CI / CD

We have a really basic CI at the moment and we want to make a Jenkins instance for the project.

## Contributors

 - [Alexandre Franquet | Miouzora](https://github.com/Miou-zora)
 - [Timothee Lesellier | Big T](https://github.com/BigT-Dev)
 - [Quentin Brejoin | Queng](https://github.com/queng123)
 - [Guylain Thomas | Jibea](https://github.com/Jibea)
 - [Lylian Hay | VyOk](https://github.com/lhay9)
 - [Mathis Evain | Kibatsu](https://github.com/Kibatsu03)
