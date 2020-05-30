# docker-ps-parser
A simple C++ program to extract the information from 'docker ps' and neatly display it, made to fit in an 80 character wide terminal.

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

## How to set up for easier use:
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
