#include <iostream>

class File {
    public:
        virtual void save() const = 0; //
};

class TextFile : public File {
    public:
        void save() const override {
            std::cout << "Saving Text file\n";
        }
};

class PDFFile : public File {
    public:
        void save() const override {
            std::cout << "Saving PDF file\n";
        }
};

void saveFile(const File* file) {
    file->save(); // Calls the save method of the appropriate class
}

int main()
{
    TextFile txt;
    PDFFile pdf;

    saveFile(&txt);
    saveFile(&pdf);
    
    return 0;
}