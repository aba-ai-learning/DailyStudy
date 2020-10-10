macro(run_main name sources)
    add_executable(${name} ${sources})
endmacro(run_main)


run_main(cppexe1  "firstcpp.cpp")
run_main(cppexe2  "sqrt.cpp")
run_main(cppexe3  "limits.cpp")
run_main(cppexe3_2  "exceed.cpp")
run_main(cppexe3_4  "hex.cpp")