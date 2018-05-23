#include <iostream>

using namespace std;

struct Node{
    int value;
    Node * next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        deletarTudo(head);
    }

    Node * deletarTudo(Node * node){
        if(node == nullptr)
            return nullptr;

       deletarTudo(node->next);
            delete node;
            return nullptr;
    }

    void deletar_tudo(){
        deletarTudo (head);
    }

    // PROCURA O VALOR, REMOVE DESSE NÓ EM DIANTE
    //    COMEÇA ASSIM >> 5 4 7 8 9 3 1
    //    CHAMA A FUNÇÃO >> cortarRabo(8)
    //    FICA ASSIM DEPOIS DE CHAMAR A FUNÇÃO >> 5 4 7
    Node * cortarRabo(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        node->next = cortarRabo(node->next, value);
        if(node->next == nullptr)
        if(node->value != value){
            delete node;
            return nullptr;
        }else{
            return node;
        }
        return node;
    }

    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    Node * _push_back(Node * node, int value){
        if(head == nullptr){
            head = new Node(value);
            return head;
        }
        if(node->next == nullptr){
            node->next = new Node(value);
            return node;
        }
        _push_back(node->next,value);
    }

    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    void rpop_back(){
        this->head = _rpop_back(head);
    }

    void show(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
private:
    void _rshow(Node * node){
        if(node == nullptr)
            return;
        cout << node->value << " ";
        _rshow(node->next);
    }

public:
    void rshow(){
        _rshow(head);
        cout << endl;
    }

    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void rremove(int value){
        head = _remove(head, value);
    }
    void iremove(int value){
        auto node = head;

        if(head == nullptr){
           return;
        }

        if(head->value == value){
           delete head;
           head = nullptr;
           return;
        }

        while(node->next->value != value){
           if(node->next == nullptr)
           return;
           node = node->next;
        }
       auto aux = node->next->next;
       delete node->next;
       node->next = nullptr;
       node->next = aux;
    }

    /*
    head = 900;
    900:{1 500};
    500:{2 700};
node700:{4 250};
    300:{6 0};
    250:{5 300};
    */

    //5
    //2 >4 X 6

    void inserir_ordenado(int value){
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

    Node * _rinserir_ordenado(Node * node, int value){
        if(node == nullptr)
            return new Node(value, node->next);
        if(node->value > value)
            return head = new Node(value, node);
        if(node->next == nullptr || node->next->value > value)
            return node->next = new Node(value, node->next);
       _rinserir_ordenado(node->next,value);
    }

    void rinserir_ordenado(int value){
        _rinserir_ordenado(head, value);
    }

    int size(){
        auto node = head;
        int contador = 0;
        while(node != nullptr){
            contador = contador + 1;
            node = node->next;
        }
        return contador;
    }

    int _rsomar(Node * node){
        if(node->next == nullptr)
            return node->value;
        return node->value + _rsomar(node->next);
    }

    int rsomar(){
           return _rsomar(head);
    }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }
};

int main()
{
    SList lista;

    cout << "Teste do push_front 3-1 e show" << endl;
    lista.push_front (3);
    lista.push_front (2);
    lista.push_front (1);
    lista.push_front (3);
    lista.show();

    cout << "Teste do push_back 4-6 e rshow" << endl;
    lista.push_back (4);
    lista.push_back (5);
    lista.push_back (6);
    lista.push_back (6);
    lista.rshow ();


    cout << "Teste do pop_front e pop_back" << endl;
    lista.pop_front ();
    lista.pop_back ();
    lista.show ();

    cout << "Teste do iremove" << endl;
    lista.iremove (6);
    lista.show ();

    cout << "Teste do rremove" << endl;
    lista.rremove (5);
    lista.show ();

    cout << "Teste do inserir_ordenado(3), rinserir_ordenado(2)+_rinserir_ordenado(head,2)" << endl;
    lista.inserir_ordenado(3);
    lista.rinserir_ordenado(2);
    lista.show();

    cout << "Teste do size" << endl;
    cout << "Size: " << lista.size () << endl;
    lista.show ();

    cout << "Teste do somar" << endl;
    cout << lista.rsomar() << endl;

    cout << "Teste do deletar_tudo" << endl;
    lista.deletar_tudo ();
    lista.show ();

    return 0;
}
