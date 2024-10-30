#include <iostream>

class Term {
public:
    int coefficient; // Hệ số
    int exponent;    // Số mũ
    Term* next;     // Con trỏ tới hạng tử tiếp theo

    Term(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

class Polynomial {
private:
    Term* head; // Đầu danh sách hạng tử

public:
    Polynomial() : head(nullptr) {}

    // Hàm thêm hạng tử
    void addTerm(int coeff, int exp) {
        if (coeff == 0) return; // Nếu hệ số bằng 0 thì không thêm

        Term* newTerm = new Term(coeff, exp);
        newTerm->next = head; // Chèn vào đầu danh sách
        head = newTerm;
    }

    // Hàm in đa thức
    void print() {
        if (!head) {
            std::cout << "0" << std::endl; // Nếu không có hạng tử nào
            return;
        }

        Term* current = head;
        while (current != nullptr) {
            if (current->coefficient > 0 && current != head) {
                std::cout << "+";
            }
            std::cout << current->coefficient << "x^" << current->exponent << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Hàm giải phóng bộ nhớ
    ~Polynomial() {
        while (head != nullptr) {
            Term* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Polynomial poly;
    int coeff, exp;
    char choice;

    std::cout << "Nhap da thuc:\n";
    
    do {
        std::cout << "Nhap he so (0 de thoat): ";
        std::cin >> coeff;
        if (coeff == 0) break; // Dừng nhập nếu hệ số là 0

        std::cout << "Nhap so mu: ";
        std::cin >> exp;

        poly.addTerm(coeff, exp); // Thêm hạng tử vào đa thức

        std::cout << "Ban co muon them hạng tử khong? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Da thuc la: ";
    poly.print(); // In ra đa thức

    return 0;
}
