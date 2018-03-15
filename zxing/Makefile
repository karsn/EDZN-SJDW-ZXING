SHELL = /bin/bash  
  
AllDirs := $(shell ls -R | grep '^\./.*:$$' | awk '{gsub(":","");print}') .  
INC_DIR := $(shell pwd)
Sources := $(foreach n,$(AllDirs) , $(wildcard $(n)/*.cpp))  
Objs := $(patsubst %.cpp,%.o, $(Sources))  
Deps := $(patsubst %.cpp,%.d, $(Sources))  
StaticLib := libzxing.a  
#DynamicLib := libisli.so  
#Bin := test_detect  
  
#AllLibs : $(DynamicLib)  
AllLibs : $(StaticLib)   
#AllLibs : $(Bin)  

ifeq ($(ARCH),arm)   

CC := arm-linux-gnueabihf-gcc
CXX := arm-linux-gnueabihf-g++
AR := arm-linux-gnueabihf-ar
SYSROOT := /home/wangsh/ISLI_Scanner/rootfs-arm/
CXXFLAGS := -g -O2 -fPIC -Wall -std=c++11
CPPFLAGS := $(foreach n,$(AllDirs) , -I$(n))  
LDFLAGS := -lstdc++  

else

CC:=gcc 
CXX:=g++
AR:=ar
SYSROOT := /
CXXFLAGS := -g -O2 -fPIC -Wall -std=c++11
#CPPFLAGS := $(foreach n,$(AllDirs) , -I$(n))  
CPPFLAGS := -I$(INC_DIR)/../
LDFLAGS := -lstdc++

endif

#ZXING_INC := $(wildcard *.h)
	
$(StaticLib) : $(Objs)  
	$(AR) rcs $@ $^
	mkdir -p out
	mkdir -p out/include/
	mkdir -p out/include/zxing/
	mkdir -p out/include/zxing/common/
	mkdir -p out/include/zxing/detector/
	
	mv $(StaticLib) out/
	cp $(wildcard *.h) out/include/zxing/
	cp $(wildcard detector/*.h) out/include/zxing/detector/
	cp $(wildcard common/*.h) out/include/zxing/common/
  
$(DynamicLib) : $(Objs)  
	$(CXX) -shared -o $@ $^ $(LDFLAGS)  
  
$(Bin) : $(Objs)  
	$(CXX) $(Objs) -o $@  
  
%.d : %.cpp  
	$(CC) -MT"$(<:.cpp=.o) $@" -MM $(CXXFLAGS) $(CPPFLAGS) $< > $@  
  
sinclude $(Deps)  

.PHONY : install
install:
	cp $(StaticLib) $(SYSROOT)/usr/lib/
#	if [ ! -d "$(SYSROOT)/usr/include/isli/"]; then mkdir $(SYSROOT)/usr/include/isli/; fi
	cp out/*.h $(SYSROOT)/usr/include/isli/
	  
.PHONY : clean  
clean:   
	rm -f $(Objs) $(Deps) $(StaticLib) $(DynamicLib) $(Bin)
	rm -rf out