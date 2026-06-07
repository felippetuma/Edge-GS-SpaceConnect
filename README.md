# 🧑‍🚀 Orbita Powered by Terrabit

### 📰 Descrição do Projeto

O projeto Orbita desenvolvido por nosso o Terrabit, é uma plataforma focada no monitoramento agrícola por meio do uso de satélites espaciais que fornecem alertas em tempo real para os produtos ruais sobre o clima, desastres naturais e pragas, controlando o terreno por hectare e plantações organizadas por área. Sendo disponiveis em dois tipos de planos o Normal no qual conta com o mapa e alertas para até 10 mil hectares e o Premium que conta com Inteligencia Artificial e recomendações para até 100 mil hectares, o preço fixo do serviço é fixado em 20 reais por hectare com a mobilidade de planos com assinaturas e pagamento mensal.

### 📖 Objetivo da Solução

Nosso objetivo é democratizar o acesso ao uso de tecnologias de munitoramento agrícola, oferecendo assim aos produtores ruais uma ferramenta inteligente que é capaz de antecipar possíveis riscos e apoiar na tomada de decisões com base em dados precisos e frequentimente atualizados. Por intermedio da integração de satélites e APIs climáticas, a nossa plataforma busca reduzir as perdas na produção que podem ser causadas por eventros climáicos extremos, desastres naturais e pragas, promovendo dessa maneira uma gestão mais eficiente, segura e sustentável das propriedades rurais, independentemente do porte da operação.

### ⚙️ Componentes Utilizados

| Nome dos componentes | Quantidade |
| -------------------- | ---------- |
| Arduino Uno | 1x |
| Breadbord | 1x |
| Jumper Macho-Macho | 11x |
| DTH22 | 1x |
| Sensor Ultrassônico | 1x |
| Painel LCD 20x4 I2C | 1x |

### 🧮 Explicação do Funcionamento

O nosso sistema é composto por um **Arduino Uno** conectado a uma protoboard no qual está sendo ligado um sensor **DHT11 ou DHT22**, que é o responsável pela leitura da temperatura e a umidade, e um sensor **Ultrassônico**, utilizado para a medição da profundidade da água e alertar possíveis alagamentos. As informações coletadas são processadas no Arduino e assim seram exibidas em tempo real no display **LCD I2C 20x4**, formando assim uma estação de munitoramento agrícola.

### 🔍 Estrutura do circuito

![Imagem do Projeto](Images/imagem-projeto.png) 

### 📝 Instruções de Execução

1. **Instalação das Bibliotecas utilizadas**

    ❗ Antes de iniciar o projeto é necessário a instalação das seguites bibliotecas no **Arduino IDE**:

    - `DHT Sensor Library` - Biblioteca responsável pela leitura do sensor DHT
    - `LiquidCrystal I2C` - Biblioteca responsável pelo controle do display LCD I2C

2. **Conexão dos Componentes:**

    - Conectar a pino `SDA` do **DHT** na pino digital 2
    - Conectar o pino do `trigger` do sensor **Ultrassônico** na pino 13 e o pino `echo` no pino 8
    - Conectar o endereço `0x27` por via das portas `SDA` (pino A4 do **Arduino**) e `SCL` (pino A5 do **Arduino**) para assim ligar o display LCD I2C.

3. **Funcionamento:**

    Após o inicializar o sistema realizara leituras contínuas dos sensores DHT e Ultrassônico e exibirá os resultados no display LCD a cada 2 segundos, com base nas seguites condições:

    - Controle do nível de água: caso a profundidade seja acima 7 cm o sistema da Orbita irá alertar um possível alagamento
    - Controle da temperatura: caso a temperatura esteja abaixo de 18ºC ou acima de 30º irá ser emitido um alerta de temperatura, entre as temperatura 18ºC e 30ºC o sistema retorná que a temperatura esta amena
    - Controle de Umidade :  com a umidade abaixo de 10% ou acima de 40% será emitido um alerta de umidade, dentro dessa faixa de porcentagem de umidade o sistema avisara que a umidade está normal.


## 👥 Integrantes da TerraBit

| Nomes dos Integrantes | RMs |
| ---------------------- | --------------- |
| Felippe Tuma | 569459 |
| Davi Yuu Santos Toyota |  569557 |
| Diego Augusto Oliveira Rocha  | 571682  |
| Renan Martins da Silva | 569549 |
| Roandry Fernades Da Silva | 569980 |