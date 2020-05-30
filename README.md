# docker-ps-parser
A simple C++ program to extract the information from `docker ps` and neatly display it in a 80 character wide terminal.

## Why use docker-ps-parser?

Don't you just hate it when commands print their output with little to no regard of how it gets displayed in your terminal window? 

Are you not sick of having to resize either the text or the terminal in order to fit long strings of text, that could have easily been arranged in a friendly looking table?
Wouldn't it be nice if that table was color coded, while we're at it?

To put it in a single sentence: Are you tired of `docker ps` printing stuff like this to your console?

<img width="597" alt="docker_ps" src="https://user-images.githubusercontent.com/28601784/83332212-a8495000-a2a2-11ea-997b-f3ea8cd8d978.png">

Well look no further! Docker-ps-parser is here to save your day. This program will take all that hard to read and poorly formatted data and slap it into a nice, 80 character wide table:

<img width="596" alt="dps_example" src="https://user-images.githubusercontent.com/28601784/83330219-4be03380-a296-11ea-9085-316f8c30e77d.png">


## How to use
1. Clone the repo:
``` 
git clone https://github.com/mikeanth-dvlp/docker-ps-parser.git 
```
2. CD into the downloaded directory: `cd docker-ps-parser`
3. Run `make`
4. Use `./dps` for a more structured output: 
```
docker ps -a --no-trunc > ./input.txt ; ./dps
```

<br>

## How to set up:
1.  Clone the repo into a dedicated directory :
```
sudo git clone https://github.com/mikeanth-dvlp/docker-ps-parser.git /usr/local/src/docker-ps-parser
```
2. Navigate into the downloaded directory: `cd /usr/local/src/docker-ps-parser`
3. Run `sudo make`
4. Make the following addition to your `.bashrc` file:
```
function dps {
        docker ps -a --no-trunc > /usr/local/src/docker-ps-parser/input.txt;
        /usr/local/src/docker-ps-parser/dps
}
```
