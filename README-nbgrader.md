-   Generate assingment:

    ``` {.bash org-language="sh"}
    nbgrader generate_assignment --assignment="01-PythonProgramming/problems" --notebook="PS1" --force
    ```

-   Get list of assingments:

    ``` {.bash org-language="sh"}
    nbgrader db assignment list
    ```

-   Autograde assingment

    ``` {.bash org-language="sh"}
    nbgrader autograde "01-PythonProgramming/problems" --notebook="PS1" #--student="name*"
    ```

-   Export grades to csv

    ``` {.bash org-language="sh"}
    nbgrader export
    ```

-   Generate solution

    ``` {.bash org-language="sh"}
    nbgrader generate_solution  --assignment="01-PythonProgramming/problems" --notebook="PS1*"
    ```

-   Generate feedback

    ``` {.bash org-language="sh"}
    nbgrader generate_feedback --assignment="01-PythonProgramming/problems" --notebook="PS2-dataStructs-numpy"
    ```

-   Delete grades database

# Numpy resources

-   <https://www.kaggle.com/code/utsav15/100-numpy-exercises>
-   <http://pycam.github.io/>

# Ideas for exam

-   Computing the fresnel integrals and comparing the numerical solution
    by the integral
-   Partial derivative potencial point charge
-   Derivative of noisy data: Integrate and then derive two times
-   Non linear acceleration, integrate and compute the velocity as a
    function of time
