#include<vector>
#include<unistd.h>
#include<signal.h>
#include<iostream>
#include <sys/types.h>
#include <sys/wait.h>


int a3input(void){

    while(!std::cin.eof()){

        std::string line;
        std::getline(std::cin,line);
        if(line.size()>0)
            std::cout<<line<<std::endl;
    }
    return 0;
}

int main(int argc, char **argv)
{
    std::vector<pid_t> kids;
    pid_t child_pid;
    // create a pipe
    int pipe_rgen_to_a1[2];
    pipe(pipe_rgen_to_a1);

    int pipe_a1_to_a2[2];
    pipe(pipe_a1_to_a2);





    child_pid = fork();
    if(child_pid == 0){


        dup2(pipe_rgen_to_a1[1],STDOUT_FILENO);
        close(pipe_rgen_to_a1[0]);
        close(pipe_rgen_to_a1[1]);
        execv("rgen",argv);
        perror("Error: Could not execute rgen");
        return 1;
    }

    else if (child_pid<0){
        std::cerr<<"Error: could not fork Rgen"<<std::endl;
        return 1;

    }
    kids.push_back(child_pid);







    child_pid = fork();
    if(child_pid == 0){
        

        char *arg1[3];
        arg1[0]= (char*)"python";
        arg1[1]=(char*)"a1-ece650.py";
        arg1[2]=nullptr;
        dup2(pipe_rgen_to_a1[0],STDIN_FILENO);
        close(pipe_rgen_to_a1[1]);
        close(pipe_rgen_to_a1[0]);


        dup2(pipe_a1_to_a2[1],STDOUT_FILENO);
        close(pipe_a1_to_a2[0]);
        close(pipe_a1_to_a2[1]);
        execvp("python",arg1);
        perror("Error: could not execute a1-ece650.py");
        return 1;
    }
    else if(child_pid<0){
        std::cerr<<"Error: could not fork a1-ece650.py"<<std::endl;
        return 1;
    }
    kids.push_back(child_pid);






    child_pid = fork();
    if(child_pid == 0){


        dup2(pipe_a1_to_a2[0],STDIN_FILENO);
        close(pipe_a1_to_a2[1]);
        close(pipe_a1_to_a2[0]);
        execv("a2-ece650",argv);
        perror("Error: could not execute a2-ece650");
        return 1;
    }
    else if(child_pid<0){
        std::cerr<<"Error: could not fork a2-ece650"<<std::endl;
        return 1;
    }
    kids.push_back(child_pid);






     child_pid = fork();
    if(child_pid == 0){


        dup2(pipe_a1_to_a2[1],STDOUT_FILENO);
        close(pipe_a1_to_a2[0]);
        close(pipe_a1_to_a2[0]);


        dup2(pipe_a1_to_a2[1],STDOUT_FILENO);
        close(pipe_a1_to_a2[0]);
        close(pipe_a1_to_a2[1]);

        return a3input();
    }
    else if(child_pid<0){
        std::cerr<<"Error: could not fork a3"<<std::endl;
        return 1;
    }
    kids.push_back(child_pid);


    int monitor;
    wait(&monitor);



    for(pid_t k:kids){
        int status;
        kill(k,SIGTERM);
        waitpid(k,&status,0);
    }

    return 0;
}
