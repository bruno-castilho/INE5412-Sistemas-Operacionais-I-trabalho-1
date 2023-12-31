# INE5412 – Sistemas Operacionais I - Trabalho 1 - Simulação de Algoritmos de Escalonamento

## Descrição
O presente trabalho tem por objetivo escrever um programa para simular o escalonamento e
abstração de um conjunto de processos/threads através do uso de algoritmos de escalonamento de
processos conhecidos na literatura. O programa deve suportar os seguintes algoritmos de
escalonamento de processos:
-  FCFS (First Come, First Served)
- Shortest Job First
- Por prioridade, sem preempção
- Por prioridade, com preempção por prioridade
- Round-Robin com quantum = 2s, sem prioridade


O programa deve ler os dados dos processos através de um arquivo de entrada, onde cada linha do
arquivo corresponde a um processo, com as seguintes informações inteiras separadas por um espaço
em braco:
- data da criação do processo
- duração em segundos
- prioridade estática (escala de prioridades positiva, ex: prioridade 3 > 2).
Um exemplo de arquivo de entrada para o programa seria (note que não tem linha em branco ao
final do arquivo):

```txt
0 5 2
0 2 3
1 4 1
3 3 4
```
Neste exemplo, o processo P1 tem data de criação 0, sua execução dura 5 segundos e sua prioridade
é definida como 2. Esse formato deve ser respeitado e não deve ser modificado em nenhuma
hipótese (a avaliação seguirá esse formato e caso haja erro de leitura o programa não executará e
consequentemente terá sua nota zerada). Note que a ordem dos processos não precisa estar ordenada
por data de criação de cada processo.

Para cada algoritmo, o programa de simulação de escalonamento de processos deverá produzir as
seguintes informações em sua saída padrão (stdout):
- Turnaround time (tempo transcorrido desde o momento em que o processo é criado até o
instante em que termina sua execução). Imprimir o turnaround time para cada processo e
também o valor médio.
- Tempo média de espera (soma dos períodos em que o processo estava no seu estado pronto).
- Número total de trocas de contexto (considerar que na primeira execução do primeiro
processo há uma troca de contexto).
- Diagrama de tempo de execução.
Para simplificar, o diagrama de tempo de cada execução pode ser gerado na vertical, de cima para
baixo (uma linha por segundo), conforme mostra o exemplo a seguir:
tempo P1 P2 P3 P4
```
tempo P1 P2 P3 P4
 0- 1 ## --
 1- 2 ## -- --
 2- 3 -- ## --
 3- 4 -- ## -- --
 4- 5 -- ## --
 5- 6 -- ## --
 6- 7 ## -- --
 7- 8 ## -- --
 8- 9 -- -- ##
 9-10 -- -- ##
10-11 -- ## --
11-12 -- ## --
12-13 ## --
13-14 ##
```

Sendo que “##” significa que o processo em questão está em execução, “--” significa que o
processo já foi criado e está esperando, “ “ (espaço em branco) o processo ainda não iniciou ou já
acabou, ou seja, não está na fila de prontos.

Sugere-se definir para cada processo as seguintes informações:
- identificador
- datas de inicio e de conclusão
- duração (tempo necessário no processador)
- prioridades estática e dinâmica (se houver)
- estado atual (novo, pronto, executando, terminado)
- tempo já executado (total e no quantum atual)
- … (outros campos podem ser necessários para algumas políticas de escalonamento)
  
Além disso, o programa de simulação deve abstrair o contexto de um processador (CPU) hipotético
chamado INE5412 que possui 6 registradores de propósito geral, SP (stack pointer), PC (program
counter) e ST (status), todos com 64 bits. Desta forma, cada abstração de processo também deve ter
um contexto (como implementar o contexto de forma a permitir a mudança de processador para a
abstração processo?). O programa de simulação deve então realizar a troca de contexto (salvar e
restaurar o contexto do processo que estava em execução e do próximo processo a ser executado -
Onde salvar o contexto do processo?)

O trabalho deve ser escrito em C++ e portanto deve apresentar as abstrações da simulação em
classes apropriadas e seus relacionamentos. A solução deve conter também uma estrutura de classes
usadas para implementar os algoritmos de escalonamento a fim de reaproveitar o código e facilitar a
adição de novas políticas no simulador (engenharia de software).

## Instalação
### Opção 1: Bare Metal
   **Passo 1: Verifique se o GCC 11.4.0 já está instalado**
    
   ```bash
   gcc --version
   ```
   
   **Passo 2: Atualize os repositórios do sistema**
    
   ```bash
   sudo apt update
   ```
   
   **Passo 3: Adicione o repositório Toolchain**
    
   ```bash
   sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
   ```
 
   **Passo 4 : Instale o GCC 11**
   
    
   ```bash
   sudo apt install -y gcc-11
   ```
    
    
   **Passo 5 : Verifique a instalação**
   
   ```bash
   gcc --version
   ```
   
### Opção 2: Docker
   **Passo 1: Baixe o script de instalação do Docker**
    
   ```bash
   curl -fsSL https://get.docker.com -o get-docker.sh
   ```
   
   **Passo 2: Execute o script**
   
   ```bash
    sudo sh ./get-docker.sh --dry-run
   ```
   **Passo 3: Verifique se a instalação foi bem sucedida executando a imagem hello-world**
   
   ```bash
    sudo docker run hello-world
   ```
   

## Compilação
### Opção 1: Bare Metal
  **Na pasta raiz do projeto, execute**
  ```bash
    make
  ```

### Opção 2: Docker
  **Na pasta raiz do projeto, execute**
   ```bash
    docker build -t scheduling-simulator .
   ```
## Execução
### Opção 1: Bare Metal
**Na pasta raiz do projeto, execute**
   ```bash
    ./main data/entrada.txt
   ```
### Opção 2: Docker
**Na pasta raiz do projeto, execute**
   ```bash
    docker run -v ./data:/data scheduling-simulator /data/entrada.txt
   ```

