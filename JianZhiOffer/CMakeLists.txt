macro(run_main name sources)
    add_executable(${name} ${sources})
endmacro(run_main)

run_main(demo001  "./001_find_integer_in_matrix/main.cpp")
run_main(demo002  "./002_replace_space/main.cpp")
run_main(demo003  "./003_print_list_tail_to_head/main.cpp")
run_main(demo004  "./004_reconstruct_bintree/main.cpp")
run_main(demo005  "./005_stack_to_queue/main.cpp")
