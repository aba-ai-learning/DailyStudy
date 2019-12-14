macro(run_main name sources)
    add_executable(${name} ${sources})
endmacro(run_main)

run_main(demo001  "./001_find_integer_in_matrix/main.cpp")
run_main(demo002  "./002_replace_space/main.cpp")
