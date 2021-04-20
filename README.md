# docker-ps-parser

![GitHub](https://img.shields.io/github/license/mikeanth-dev/docker-ps-parser?style=for-the-badge)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/mikeanth-dev/docker-ps-parser?style=for-the-badge)
![GitHub top language](https://img.shields.io/github/languages/top/mikeanth-dev/docker-ps-parser?style=for-the-badge)
![Build status](https://img.shields.io/gitlab/pipeline/mikeanth-dev/docker-ps-parser/master?style=for-the-badge)

A simple C++ program to extract the information from `docker ps` and neatly display it in a 80 character wide terminal.

## Why use docker-ps-parser?

Don't you just hate it when commands print their output with little to no regard of how it gets displayed in your terminal window? :rage:

Are you not sick of having to resize either the text or the terminal in order to fit long strings of characters, that could have easily been arranged in a friendly looking table?
Wouldn't it be nice if that table was color coded, while we're at it?

To put it in a single sentence: Are you tired of `docker ps` printing stuff like this to your console?

!['docker ps example'](https://user-images.githubusercontent.com/28601784/83340452-ef563600-a2e0-11ea-90b8-47cc2a84de81.png)

Well look no further! Docker-ps-parser is here to save your day. This program will take all that hard to read and poorly formatted data and slap it into a nice, 80 character wide table:

!['dps example'](https://user-images.githubusercontent.com/28601784/83340455-f2512680-a2e0-11ea-81d8-42799dfbda6b.png)

"But wait!", I hear you say, "Can't you kinda sorta already do that with `docker ps --format "table {{.Names}}\\t{{.Image}}\\t{{.Status}}\\t{{.Ports}}"`?". And you would be right ... nerd :nerd_face: . However, the way it handles multiple ports is still kind of funky and if you have more than, say, 3 ports on a single container, well then, we're back to ground zero:

!['docker ps table'](https://user-images.githubusercontent.com/28601784/83340454-f11ff980-a2e0-11ea-8a85-d7dd04e6daf6.png)

Also, have you not seen the pretty colors in the table?? :heart_eyes:

## How to setup

Check out the [releases page](https://github.com/mikeanth-dev/docker-ps-parser/releases) for precompiled binaries.  
See the [wiki](https://github.com/mikeanth-dev/docker-ps-parser/wiki) for more detailed steps.  

## Feedback, suggestions and help

For feedback, suggestions, bug reports etc., feel free to e-mail me at 'mike.anth99@gmail.com'.

---

_a project by Mircea-Pavel Anton (Mike Anthony)_
