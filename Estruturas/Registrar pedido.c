#include <stdio.h>
#include <string.h>

struct Pizza {
    char nome[30];
    float preco;
    char tamanho; // P, M e G
};

struct Cliente {
    char nome[50];
    char endereco[100];
    char telefone[15];
};

// Definição da estrutura do pedido
struct Pedido {
    struct Cliente cliente;
    struct Pizza pizzas[5]; 
    int quantidadePizzas;
    float total;
};

// Função para cadastrar o cliente
void cadastrarCliente(struct Cliente *cliente) {
    printf("Digite o nome do cliente: ");
    fgets(cliente->nome, sizeof(cliente->nome), stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = 0; 

    printf("Digite o endereco do cliente: ");
    fgets(cliente->endereco, sizeof(cliente->endereco), stdin);
    cliente->endereco[strcspn(cliente->endereco, "\n")] = 0; // 

    printf("Digite o telefone do cliente: ");
    fgets(cliente->telefone, sizeof(cliente->telefone), stdin);
    cliente->telefone[strcspn(cliente->telefone, "\n")] = 0; // 
}

// Função para registrar um pedido
void registrarPedido(struct Pedido *pedido, struct Cliente cliente, struct Pizza *cardapio, int tamanhoCardapio) {
    pedido->cliente = cliente;
    
    printf("\nDigite o número de pizzas que o cliente deseja (máximo 5): ");
    scanf("%d", &pedido->quantidadePizzas);


    if (pedido->quantidadePizzas > 5) {
        printf("Máximo de 5 pizzas permitidas.\n");
        pedido->quantidadePizzas = 5;
    }

    // Registrar as pizzas
    pedido->total = 0;
    for (int i = 0; i < pedido->quantidadePizzas; i++) {
        int escolha;
        printf("\nEscolha a pizza %d:\n", i + 1);
        for (int j = 0; j < tamanhoCardapio; j++) {
            printf("%d. %s (Preço: R$%.2f) Tamanho: %c\n", j + 1, cardapio[j].nome, cardapio[j].preco, cardapio[j].tamanho);
        }
        printf("Digite o número da pizza escolhida: ");
        scanf("%d", &escolha);

        // Verificar se a escolha está dentro do intervalo válido
        if (escolha >= 1 && escolha <= tamanhoCardapio) {
            pedido->pizzas[i] = cardapio[escolha - 1];
            pedido->total += pedido->pizzas[i].preco; // Adicionar o preço ao total
        } else {
            printf("Escolha inválida! Tente novamente.\n");
            i--; // Tentar novamente a mesma pizza
        }
    }
}

// Função para exibir o pedido
void exibirPedido(struct Pedido pedido) {
    printf("\n--- Detalhes do Pedido ---\n");
    printf("Cliente: %s\n", pedido.cliente.nome);
    printf("Endereço: %s\n", pedido.cliente.endereco);
    printf("Telefone: %s\n", pedido.cliente.telefone);
    printf("\nPizzas do Pedido:\n");
    for (int i = 0; i < pedido.quantidadePizzas; i++) {
        printf("Pizza %d: %s (Tamanho: %c) - R$%.2f\n", i + 1, pedido.pizzas[i].nome, pedido.pizzas[i].tamanho, pedido.pizzas[i].preco);
    }
    printf("\nTotal do Pedido: R$%.2f\n", pedido.total);
}

int main() {
    struct Pizza cardapio[3] = {
        {"Calabresa", 30.50, 'M'},
        {"Marguerita", 25.00, 'G'},
        {"Portuguesa", 28.00, 'P'}
    };
    
    struct Cliente cliente;
    struct Pedido pedido;

    // Cadastrar o cliente
    cadastrarCliente(&cliente);

    // Registrar o pedido
    registrarPedido(&pedido, cliente, cardapio, 3);

    // Exibir o pedido
    exibirPedido(pedido);

    return 0;
}
