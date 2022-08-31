VPATH= src bin obj include
src_content=./src/
bin_content=./bin/
obj_content=./obj/



all:manage

manage:main.o datebase.o filecontrol.o function.o
	gcc -o $(bin_content)$@ $^ 
main.o:
	gcc -c $(src_content)main.c -o $(obj_content)$@
datebase.o:
	gcc -c $(src_content)datebase.c -o $(obj_content)$@
filecontrol.o:
	gcc -c $(src_content)filecontrol.c -o $(obj_content)$@
function.o:
	gcc -c $(src_content)function.c -o $(obj_content)$@


clean:
	rm -rf *.o manage