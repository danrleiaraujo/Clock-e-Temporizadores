<h1 align="center">
  <br>
    <img width="400px" src="https://github.com/danrleiaraujo/Clock-e-Temporizadores/tree/main/Tarefa-2-Temporizador-de-um-disparo/src/logo.png"> 
  <br>
    Unidade 4 - Capítulo 5 - Atividade 1: Temporizador de um disparo.
  <br>
</h1>
<div align="center">

</div>

<div align="center"> 
  
Esta atividade tem como objetivo usar o Raspberry Pi Pico W para compreender o funcionamento e aplicação de temporizador de um disparo (One shot). O projeto envolve programação em C, integração com o SDK do Raspberry Pi Pico e o simulador Wokwi. 
</div>

<details open="open">
<summary>Sumário</summary>
  
- [Requisitos](#requisitos)
- [Componentes Utilizados](#componentes-utilizados)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Funcionalidades](#funcionalidades)
- [Como Executar](#como-executar)
  - [Pré-requisitos](#pré-requisitos)
  - [Passos para Execução](#passos-para-execução)
- [Autor](#autor)

</details>

## Requisitos

O projeto deve cumprir os seguintes requisitos:

1. **O acionamento dos LEDs**: Caso o usuario clique no botão, deverá acender os três LEDs (todos em nível alto). A partir da primeira rotina de atraso, ocorrerá uma mudança de estado para dois LEDs ligados e em seguida, apenas um.
2. **Temporizador**: Deve ser ajustado para um atraso de 3 segundos (3.000ms) entre o estado de acionamento entre os leds.
3. **Call-Back**: A mudança de estado dos LEDs deve ser implementa em funções de call-back do temporizador.
4. **Ativação pós desligamento**: O botão só pode alterar o estado dos LEDs quando o ultimo LED for desligado.
3. **Debounce**: Implementar uma rotina em software para atenuação do efeito bouncing no botão.


## Componentes Utilizados

1. **Raspberry Pi Pico W**: Microcontrolador para controle do sistema.
2. **LED RGB (na placa BitDogLab) ou 3 LEDs de cores diferentes (no Simulador)**: Interface para visualização do temporizador.
4. **VS Code**: Ambiente de desenvolvimento para código em linguagem C.
5. **Simulador Wokwi**: Para simulação do circuito.
  <div align="center">
      <img width="800px" src="https://github.com/danrleiaraujo/Clock-e-Temporizadores/tree/main/Tarefa-2-Temporizador-de-um-disparo/src/image.png" />
      <p>Fig 1. Projeto no simulador .</p>
   </div>
   
## Estrutura do Projeto

- **OneShot.c**: Código responsável pela configuração.

## Funcionalidades 
- **Botão**: Ao clicar liga as três LEDs.

## Como Executar

### Pré-requisitos

1. **Git**: Certifique-se de ter o Git instalado no seu sistema. 
2. **VS Code**: Instale o Visual Studio Code, um editor de código recomendado para desenvolvimento com o Raspberry Pi Pico.
3. **Pico SDK**: Baixe e configure o SDK do Raspberry Pi Pico, conforme as instruções da documentação oficial.
4. **Simulador Wokwi**: Utilize o simulador de eletrônica Wokwi para simular o projeto, caso não tenha acesso à placa física.
5. **Conexão USB**: Certifique-se de que o Raspberry Pi Pico W esteja conectado via USB quando for testar o código.

### Passos para Execução

1. **Clonar o repositório**: Clone o repositório utilizando o comando Git no terminal:
   
   ```bash
   git clone https://github.com/danrleiaraujo/Clock-e-Temporizadores.git
   ```
2. Abrir no VS Code: Abra a pasta clonada no VS Code e no terminal do VS Code, vá até a pasta do projeto. (Tarefa-2-Temporizador-de-um-disparo)
3. Compilar o código.



## Autor

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/danrleiaraujo" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/44043273?v=4" width="100px;" alt=""/>
      </a>
      <br /><sub><b> Danrlei Araujo</b></sub>
    </td>
  </tr>
</table>

