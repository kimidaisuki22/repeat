#include <cerrno>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc,char** argv){
	while(true){

		if(auto cid = fork()){
			int ret;
			waitpid(cid, &ret,WCONTINUED );
			if(ret==0){
				exit(0);
			}

		}else{
			std::cout <<"running argv[1]\n";
			execvp(argv[1], argv+1);
			std::string cmd;
			for(int i=1;i<argc;i++){
				cmd +=argv[i]  ;
				cmd +=" "   ;
			}
//			return system(cmd.c_str());
			std::cout << strerror(errno) <<"\n";
		}
	}
	return 0;
}
