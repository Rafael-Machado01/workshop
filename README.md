# Projeto Bimestral - Luiz Ricardo Begosso

### Escreva um programa em C++ para criar as seguintes estruturas que simularão arquivos sequenciais para uma aplicação de gerenciamento de uma Oficina Mecânica:

- Cidades: código, nome, UF
- Clientes: código, nome, endereço, telefone, código_cidade
- Veículos: placa, modelo, marca, ano, código_cliente
- Serviços: código, descrição, valor_mão_de_obra
- Peças: código, descrição, quant_estoque, estoque_minimo, estoque_maximo, preço_unitario
- Mecânicos: código, nome, especialidade, telefone
- Ordens de Serviço: código, placa_veiculo, código_mecanico, data, código_serviço, código_peça, quantidade peça

1. Escreva funções específicas para a leitura dos dados das estruturas: Cidades, Serviços e Peças.

2. Escreva uma função para permitir a inclusão de novos registros na tabela de Clientes.

- 2.1) O programa deverá garantir que o código do cliente a ser inserido não existe na tabela de Clientes.

- 2.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e UF.

3. Escreva uma função para permitir a inclusão de novos registros na tabela de Veículos.
   - 3.1) O programa deverá garantir que a placa do veículo a ser inserido não existe na tabela de Veículos.
   - 3.2) Quando o usuário digitar o código do cliente, o programa deverá buscar este código na tabela de Clientes e exibir o nome do cliente.

4. Escreva uma função para permitir a inclusão de novos registros na tabela de Mecânicos.

5. Escreva uma função para permitir a abertura de uma Ordem de Serviço.
   - 5.1) Quando o usuário digitar a placa do veículo, o programa deverá buscar este dado na tabela de Veículos e exibir o modelo e o nome do cliente.

   - 5.2) Quando o usuário digitar o código do mecânico, o programa deverá buscar este código na tabela de Mecânicos e exibir o nome e a especialidade.

   - 5.3) Quando o usuário digitar o código do serviço, o programa deverá buscar este código na tabela de Serviços e exibir a descrição e o valor da mão de obra.

   - 5.4) Quando o usuário digitar o código da peça, o programa deverá buscar este código na tabela de Peças e exibir a descrição.

   - 5.5) Quando o usuário digitar a quantidade de peças:
     O programa deverá verificar se a quantidade em estoque é suficiente.
     O programa não deverá permitir informar quantidade maior do que a disponível.
   - 5.6) A quantidade de peças utilizada deverá ser subtraída do estoque.

6. Escreva uma função para permitir ao usuário consultar os dados de determinada peça.
   - 6.1) Para cada peça consultada, exibir:
     Todos os seus dados
     O valor total em estoque (quant_estoque × preço_unitario)

7. Escreva uma função para exibir todas as peças que estejam com a quantidade em estoque abaixo do estoque mínimo.

- 7.1) As seguintes informações devem ser exibidas:
  Código, Descrição, Quantidade em estoque, Estoque máximo, Quantidade a ser comprada, Valor da compra

- 7.1.1) A quantidade a ser comprada é calculada pela diferença entre o estoque máximo e a quantidade em estoque.

- 7.2) Ao final, a função deverá exibir o valor total a ser gasto na compra das peças.

8. Escreva uma função para exibir o valor total arrecadado com todas as ordens de serviço.

- 8.1) O valor de cada ordem de serviço deve ser calculado pela soma:
  Valor da mão de obra do serviço
  Valor das peças utilizadas (quantidade × preço unitário)

#### Observações:

- Todas as funções descritas acima deverão ser chamadas através de um menu de opções, que será implementado na função main().
- Não utilizar variáveis globais
- Utilizar estruturas para representar as tabelas
- As buscas devem ser realizadas de forma aleatória
- Garantir validações conforme especificado em cada item
