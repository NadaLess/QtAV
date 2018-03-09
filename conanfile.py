from conans import ConanFile
from conans import tools

class QtavConan(ConanFile):
    #name = "qtav"
    #version = "1.12.0"
    settings = "os", "compiler", "build_type", "arch"
    description = "<Description of Qtav here>"
    url = "None"
    license = "None"

    def package(self):
        self.copy("*")

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
        self.cpp_info.includedirs.extend(["include/QtAV"])

