# docker-ps-parser
A simple C++ program to extract the information from 'docker ps' and neatly display it, made to fit in an 80 character wide terminal.

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

## How to set up for ease of use
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
