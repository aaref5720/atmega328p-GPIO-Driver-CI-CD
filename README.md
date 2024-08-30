# CI/CD for Embedded Software

## Overview

This repository demonstrates the implementation of Continuous Integration (CI) and Continuous Deployment (CD) pipelines for embedded software. The goal is to ensure that embedded software projects have automated testing, static analysis, and code quality checks integrated into the development process. 

## CI/CD Pipeline

### CI/CD Pipeline Description

The CI/CD pipeline is configured using GitHub Actions to automate the build, test, and analysis processes. This setup ensures that code changes are automatically built and tested, and code quality is maintained throughout the development lifecycle.

### Pipeline Configuration

The pipeline is defined in the `.github/workflows/ci.yaml` file. It includes the following steps:

1. **Checkout Code**: The pipeline starts by checking out the latest code from the repository.

2. **Install Dependencies**: Dependencies such as build tools and static analysis tools are installed.

3. **List Files**: Lists the files in the repository for debugging purposes.

4. **Print Current Directory**: Prints the current working directory for debugging purposes.

5. **Display Makefile**: Displays the contents of the `Makefile` to verify its presence and contents.

6. **Build Project**: Compiles the project using `make all`.

7. **Run Unit Tests**: Executes unit tests using `make test`.

8. **Static Analysis**: Runs static analysis on the source code using `cppcheck` to identify potential issues.

9. **Code Coverage**: Captures code coverage information using `lcov`.

10. **Upload Coverage Report**: Uploads the coverage report as an artifact for review.

## Contributing

Contributions to this project are welcome! If you have ideas for further optimization or improvements, feel free to open an issue or submit a pull request.
