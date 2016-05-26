##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=week 1
ConfigurationName      :=Debug
WorkspacePath          := "/media/luong/Private Data/CS162 LAB/week 1"
ProjectPath            := "/media/luong/Private Data/CS162 LAB/week 1"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Luong Vo
Date                   :=24/05/16
CodeLitePath           :="/home/luong/.codelite"
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="week 1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/ex01.1_fraction.cpp$(ObjectSuffix) $(IntermediateDirectory)/ex01.1_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ex01.2_fraction.cpp$(ObjectSuffix) $(IntermediateDirectory)/ex01.2_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ex02.2_function.cpp$(ObjectSuffix) $(IntermediateDirectory)/ex02.2_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ex02.3_function.cpp$(ObjectSuffix) $(IntermediateDirectory)/ex02.3_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ex2.1_function.cpp$(ObjectSuffix) $(IntermediateDirectory)/ex2.1_main.cpp$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ex01.1_fraction.cpp$(ObjectSuffix): ex01.1/fraction.cpp $(IntermediateDirectory)/ex01.1_fraction.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex01.1/fraction.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex01.1_fraction.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex01.1_fraction.cpp$(DependSuffix): ex01.1/fraction.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex01.1_fraction.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex01.1_fraction.cpp$(DependSuffix) -MM "ex01.1/fraction.cpp"

$(IntermediateDirectory)/ex01.1_fraction.cpp$(PreprocessSuffix): ex01.1/fraction.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex01.1_fraction.cpp$(PreprocessSuffix) "ex01.1/fraction.cpp"

$(IntermediateDirectory)/ex01.1_main.cpp$(ObjectSuffix): ex01.1/main.cpp $(IntermediateDirectory)/ex01.1_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex01.1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex01.1_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex01.1_main.cpp$(DependSuffix): ex01.1/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex01.1_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex01.1_main.cpp$(DependSuffix) -MM "ex01.1/main.cpp"

$(IntermediateDirectory)/ex01.1_main.cpp$(PreprocessSuffix): ex01.1/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex01.1_main.cpp$(PreprocessSuffix) "ex01.1/main.cpp"

$(IntermediateDirectory)/ex01.2_fraction.cpp$(ObjectSuffix): ex01.2/fraction.cpp $(IntermediateDirectory)/ex01.2_fraction.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex01.2/fraction.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex01.2_fraction.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex01.2_fraction.cpp$(DependSuffix): ex01.2/fraction.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex01.2_fraction.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex01.2_fraction.cpp$(DependSuffix) -MM "ex01.2/fraction.cpp"

$(IntermediateDirectory)/ex01.2_fraction.cpp$(PreprocessSuffix): ex01.2/fraction.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex01.2_fraction.cpp$(PreprocessSuffix) "ex01.2/fraction.cpp"

$(IntermediateDirectory)/ex01.2_main.cpp$(ObjectSuffix): ex01.2/main.cpp $(IntermediateDirectory)/ex01.2_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex01.2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex01.2_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex01.2_main.cpp$(DependSuffix): ex01.2/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex01.2_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex01.2_main.cpp$(DependSuffix) -MM "ex01.2/main.cpp"

$(IntermediateDirectory)/ex01.2_main.cpp$(PreprocessSuffix): ex01.2/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex01.2_main.cpp$(PreprocessSuffix) "ex01.2/main.cpp"

$(IntermediateDirectory)/ex02.2_function.cpp$(ObjectSuffix): ex02.2/function.cpp $(IntermediateDirectory)/ex02.2_function.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex02.2/function.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex02.2_function.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex02.2_function.cpp$(DependSuffix): ex02.2/function.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex02.2_function.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex02.2_function.cpp$(DependSuffix) -MM "ex02.2/function.cpp"

$(IntermediateDirectory)/ex02.2_function.cpp$(PreprocessSuffix): ex02.2/function.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex02.2_function.cpp$(PreprocessSuffix) "ex02.2/function.cpp"

$(IntermediateDirectory)/ex02.2_main.cpp$(ObjectSuffix): ex02.2/main.cpp $(IntermediateDirectory)/ex02.2_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex02.2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex02.2_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex02.2_main.cpp$(DependSuffix): ex02.2/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex02.2_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex02.2_main.cpp$(DependSuffix) -MM "ex02.2/main.cpp"

$(IntermediateDirectory)/ex02.2_main.cpp$(PreprocessSuffix): ex02.2/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex02.2_main.cpp$(PreprocessSuffix) "ex02.2/main.cpp"

$(IntermediateDirectory)/ex02.3_function.cpp$(ObjectSuffix): ex02.3/function.cpp $(IntermediateDirectory)/ex02.3_function.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex02.3/function.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex02.3_function.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex02.3_function.cpp$(DependSuffix): ex02.3/function.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex02.3_function.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex02.3_function.cpp$(DependSuffix) -MM "ex02.3/function.cpp"

$(IntermediateDirectory)/ex02.3_function.cpp$(PreprocessSuffix): ex02.3/function.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex02.3_function.cpp$(PreprocessSuffix) "ex02.3/function.cpp"

$(IntermediateDirectory)/ex02.3_main.cpp$(ObjectSuffix): ex02.3/main.cpp $(IntermediateDirectory)/ex02.3_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex02.3/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex02.3_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex02.3_main.cpp$(DependSuffix): ex02.3/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex02.3_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex02.3_main.cpp$(DependSuffix) -MM "ex02.3/main.cpp"

$(IntermediateDirectory)/ex02.3_main.cpp$(PreprocessSuffix): ex02.3/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex02.3_main.cpp$(PreprocessSuffix) "ex02.3/main.cpp"

$(IntermediateDirectory)/ex2.1_function.cpp$(ObjectSuffix): ex2.1/function.cpp $(IntermediateDirectory)/ex2.1_function.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex2.1/function.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex2.1_function.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex2.1_function.cpp$(DependSuffix): ex2.1/function.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex2.1_function.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex2.1_function.cpp$(DependSuffix) -MM "ex2.1/function.cpp"

$(IntermediateDirectory)/ex2.1_function.cpp$(PreprocessSuffix): ex2.1/function.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex2.1_function.cpp$(PreprocessSuffix) "ex2.1/function.cpp"

$(IntermediateDirectory)/ex2.1_main.cpp$(ObjectSuffix): ex2.1/main.cpp $(IntermediateDirectory)/ex2.1_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/luong/Private Data/CS162 LAB/week 1/ex2.1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ex2.1_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ex2.1_main.cpp$(DependSuffix): ex2.1/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ex2.1_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ex2.1_main.cpp$(DependSuffix) -MM "ex2.1/main.cpp"

$(IntermediateDirectory)/ex2.1_main.cpp$(PreprocessSuffix): ex2.1/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ex2.1_main.cpp$(PreprocessSuffix) "ex2.1/main.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


