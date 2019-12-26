macro(run_main name sources)
    add_executable(${name} ${sources})
endmacro(run_main)

run_main(ldemo001  "./001_two_sum/main.cpp")

