macro(run_main name sources)
    add_executable(${name} ${sources})
endmacro(run_main)

run_main(ldemo001  "./001_two_sum/main.cpp")
run_main(ldemo002  "./002_two_add/main.cpp")
run_main(ldemo007  "./007_reverse_int/main.cpp")
run_main(ldemo008  "./008_atoi/main.cpp")
run_main(ldemo015  "./015_three_sum/main.cpp")
run_main(ldemo1292 "./1292_max_side_length/main.cpp")

