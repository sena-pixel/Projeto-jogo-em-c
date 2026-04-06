# Projeto-jogo-em-c

# 1. 🎮 Hub de Jogos em C

Este é um projeto desenvolvido em linguagem C que reúne três jogos interativos em um único menu (Hub). O código foi estruturado para ser **multiplataforma**, funcionando tanto em Windows quanto em Linux/Unix.

---

## 🚀 Como Executar

### Pré-requisitos
* Um compilador de C (GCC, Clang ou MinGW).

### Passo a passo
1. Clone este repositório ou baixe o arquivo `.c`.
2. Abra o terminal na pasta do arquivo.
3. Compile o código:
   ```bash
   gcc nome_do_seu_arquivo.c -o hub_jogos
   ```
4. Execute o programa:
   * **Windows:** `hub_jogos.exe`
   * **Linux/Mac:** `./hub_jogos`

---

## 🕹️ Jogos Inclusos

### 1. Perguntas e Respostas ❓
Um quiz clássico de conhecimentos gerais. O jogador deve escolher a alternativa correta para avançar. Inclui validação de entrada para evitar erros.

### 2. Cobra na Caixa 🐍
Um jogo de sorte e estratégia para dois jogadores!
* Escolha seus personagens egípcios.
* Abram as caixas uma por uma.
* **Objetivo:** Achar o botão de vitória antes de encontrar a cobra escondida!

### 3. Gousmas War ⚔️
Um jogo de combate por turnos utilizando **Structs** e lógica de fúria.
* Cada jogador controla duas "Gousmas".
* Ataque o oponente para aumentar a fúria dele.
* **Cuidado:** Se a fúria de uma Gousma ultrapassar o limite, ela explode!

---

## 🛠️ Tecnologias e Conceitos Utilizados

* **Linguagem C**: Base de todo o projeto.
* **Estruturas de Repetição**: Uso intensivo de `while`, `do-while` e `for`.
* **Condicionais**: `if/else` e `switch-case` para o menu e regras dos jogos.
* **Multiplataforma**: Uso de `#ifdef` para comandos de limpar tela (`cls`/`clear`) e pausa (`Sleep`/`usleep`).
* **Gerenciamento de Memória**: Limpeza de buffer de entrada (`getchar`).
* **Structs e Typedef**: Organização de dados complexos no jogo Gousmas War.

---

## 👤 Autor

Desenvolvido por **Seu Nome Aqui** durante o aprendizado de lógica de programação e estruturas de controle em C.
```

---

### Dicas para o GitHub:

1.  **Edite o Nome:** No final do texto, troque "Seu Nome Aqui" pelo seu nome real ou seu usuário do GitHub.
2.  **Imagens:** Se você quiser deixar o README incrível, tire um *print* do menu do jogo rodando no seu terminal e adicione no repositório.
3.  **Extensão:** Certifique-se de que o nome do arquivo seja exatamente `README.md` (em letras maiúsculas). O GitHub reconhece esse nome automaticamente e o exibe logo abaixo da lista de arquivos.

Você já sabe como criar esse arquivo `.md` ou quer que eu te ajude com os comandos para subir ele junto com o código?
