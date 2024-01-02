# Fossil XMock - C

Fossil Standard Component Libraries (FSCL) by Fossil Logic represent the pinnacle of software development, embodying our commitment to quality, security, and practicality. These meticulously curated libraries serve as the cornerstone for crafting cutting-edge applications, offering a foundation built on excellence in code. With FSCL, Fossil Logic empowers developers to seamlessly integrate standardized components that elevate the overall performance and reliability of digital solutions, setting a new standard for software excellence.

Unleash the power of mock objects and simulated environments with Fossil XMock. This library empowers developers to create realistic simulations for testing, enabling a more controlled and efficient software development lifecycle. Enhance the accuracy of your testing scenarios, leading to the creation of more resilient and adaptable applications.

## Who is This For?

This guide is designed for developers of all skill levels who want to use the Meson build system for their projects. It assumes basic familiarity with command-line interfaces and project organization.

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Setting up Meson Build

1. **Install Meson**:
   - Follow the installation instructions on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## Setting up, Compiling, Installing, and Running the Project

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/fossil-lib/fscl-xmock-c.git
   cd trilo-xmock-c
   ```

2. **Configure the Build**:
   ```bash
   meson setup builddir
   ```

3. **Compile the Project**:
   ```bash
   meson compile -C builddir
   ```

4. **Install the Project**:
   ```bash
   meson install -C builddir
   ```

## Including the Demo and Running Tests

To run tests, you can use the following options when configuring the build:

- **Running Tests**: Add `-Dwith_test=enabled` when configuring the build.

Example:

```bash
meson setup builddir -Dwith_test=enabled
```

## Contributing

If you're interested in contributing to this project, please consider opening pull requests or creating issues on the [GitHub repository](https://github.com/fossil-lib/fscl-xmock-c). Be sure to read the documentation on the [project website](https://trilobite.home.blog).

## Feedback and Support

If you encounter any issues, have questions, or would like to provide feedback, don't hesitate to open an issue on the [GitHub repository](https://github.com/fossil-lib/fscl-xmock-c/issues).

## License

This project is licensed under the [Apache License 2.0](LICENSE).

---

Thank you for choosing this project with the Meson build system. Happy coding and building amazing projects!

## Contact

If you have questions or want to get in touch regarding programming solutions, you can find a way to contact me on my [website](https://trilobite.home.blog/contact/).
