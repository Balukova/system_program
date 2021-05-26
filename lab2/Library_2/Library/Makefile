CCX = g++
MAIN := main_db
MAIN_DB := main_db
MAIN_NAME := UI
MAIN_NAME_DB := UI
BUILD_DIR := ./buildDir
STATIC_LIB := lib_static
DYNAMIC_LIB := lib_dynamic

SRC := Worker.cpp DataBase.cpp
OBJS := $(SRC:%=$(BUILD_DIR)/%.o)

collect_static : $(BUILD_DIR)/$(MAIN)_s

# collecting main and static library
$(BUILD_DIR)/$(MAIN)_s : $(BUILD_DIR)/$(MAIN_NAME).o $(BUILD_DIR)/$(STATIC_LIB).a
	@$(CCX) -o $@ $< -L$(BUILD_DIR) -l_static

# compiling main file
$(BUILD_DIR)/$(MAIN_NAME).o: $(MAIN_NAME).cpp
	@$(CXX)  -c $< -o $@

# creating a static library:
$(BUILD_DIR)/$(STATIC_LIB).a : $(OBJS)
	@ar crs $@ $^

collect_dynamic : $(BUILD_DIR)/$(MAIN)_d
# collecting main and dynamic library
$(BUILD_DIR)/$(MAIN)_d : $(MAIN_NAME).cpp $(BUILD_DIR)/$(DYNAMIC_LIB).so
	@$(CCX) $< -o $@ -L $(BUILD_DIR) -l_dynamic

# creating a dynamic library:
$(BUILD_DIR)/$(DYNAMIC_LIB).so : $(OBJS)
	@$(CCX) $^ -shared  -o $@ -lc

# compile files
$(BUILD_DIR)/%.cpp.o : %.cpp
	@$(CXX) -c -fPIC $< -o $@


clean:
	@rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.a $(BUILD_DIR)/*.so $(BUILD_DIR)/$(MAIN)
	@rm $(BUILD_DIR)/$(MAIN)_s
	@rm $(BUILD_DIR)/$(MAIN)_d

clean_src:
	@rm -f *.o *.a *.so

run_static:
	@./$(BUILD_DIR)/$(MAIN)_s

run_dynamic:
	@./$(BUILD_DIR)/$(MAIN)_d


