#!/usr/bin/env bash

#pip install git+https://github.com/jupyter/nbgrader.git@v0.8.0a2

pip install nbgrader

jupyter server extension enable --sys-prefix --py nbgrader.server_extensions.formgrader
jupyter server extension enable --sys-prefix --py nbgrader.server_extensions.assignment_list
jupyter server extension enable --sys-prefix --py nbgrader.server_extensions.course_list
jupyter server extension enable --sys-prefix --py nbgrader.server_extensions.validate_assignment

jupyter labextension enable --level=sys_prefix nbgrader/formgrader
jupyter labextension enable --level=sys_prefix nbgrader/assignment-list
jupyter labextension enable --level=sys_prefix nbgrader/course-list
jupyter labextension enable --level=sys_prefix nbgrader/create-assignment
jupyter labextension enable --level=sys_prefix nbgrader/validate-assignment

jupyter labextension enable nbgrader/formgrader
jupyter labextension enable nbgrader/assignment-list
jupyter labextension enable nbgrader/course-list
jupyter labextension enable nbgrader/create-assignment
jupyter labextension enable nbgrader/validate-assignment

jupyter labextension list
jupyter server extension list
