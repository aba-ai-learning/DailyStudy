macro(run_main name sources)
    add_executable(${name} ${sources})
endmacro(run_main)

# run_main(string2int  "./String_ByteDance/string2int.cpp")
run_main(gameoflife  "./Array/0289_gameOfLife.cpp")

