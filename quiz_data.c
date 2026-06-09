#include "quiz_data.h"

const QuizItem QUESTIONS[MAX_QUESTIONS] = {
    {
        "Era Mecânica", "Séc. XVII – XIX",
        "O Tear de Jacquard (1804)",
        "Em 1804, Joseph-Marie Jacquard inventou um tear controlado\n"
        "por cartões perfurados. Cada cartão definia o padrão do tecido.\n"
        "Esse mecanismo inspirou diretamente Charles Babbage e,\n"
        "décadas depois, os primeiros computadores com cartões perfurados.",
        "Quem inventou a Máquina Analítica – o primeiro projeto de\n"
        "computador mecânico de uso geral?",
        {"Ada Lovelace", "Blaise Pascal", "Charles Babbage", "Alan Turing"},
        2
    },
    {
        "Primeira Programadora", "1843",
        "Ada Lovelace – A 1ª Programadora da História",
        "Ada Lovelace traduziu um artigo sobre a Máquina Analítica e\n"
        "adicionou notas 3x mais longas que o original. Nelas descreveu\n"
        "o primeiro algoritmo destinado a ser processado por uma máquina.\n"
        "Por isso é considerada a primeira programadora da história.",
        "Ada Lovelace foi filha de qual famoso poeta inglês?",
        {"William Shakespeare", "Lord Byron", "John Keats", "Percy Shelley"},
        1
    },
    {
        "Era Eletromecânica", "Déc. 1930–40",
        "A Máquina Enigma e a Criptoanálise",
        "Durante a 2ª Guerra Mundial, a Alemanha usou a máquina Enigma\n"
        "para cifrar mensagens. Alan Turing liderou a equipe em Bletchley\n"
        "Park que quebrou o código. Estima-se que isso encurtou a guerra\n"
        "em 2 a 4 anos e salvou milhões de vidas.",
        "Como se chama a máquina criada por Turing para\n"
        "decifrar a Enigma?",
        {"Colossus", "The Bombe", "ENIAC", "Z3"},
        1
    },
    {
        "Primeiro Computador Eletrônico", "1945",
        "ENIAC – 18.000 Válvulas",
        "O ENIAC (1945) pesava 27 toneladas, ocupava 167 m² e\n"
        "consumia 150 kW de energia. Ele realizava 5.000 somas por\n"
        "segundo – feito extraordinário para a época. Era 'programado'\n"
        "reconectando cabos manualmente.",
        "Para qual fim o ENIAC foi originalmente desenvolvido?",
        {
            "Prever o tempo",
            "Cálculos de trajetória de artilharia",
            "Controlar redes elétricas",
            "Processar censos populacionais"
        },
        1
    },
    {
        "Transistor & Circuito Integrado", "1947 – 1958",
        "Do Transistor ao Chip",
        "Em 1947 Bell Labs inventou o transistor, substituindo as\n"
        "válvulas. Em 1958, Jack Kilby (Texas Instruments) integrou\n"
        "vários transistores num único chip de silício – o Circuito\n"
        "Integrado. Isso disparou a Lei de Moore: dobrando transistores\n"
        "a cada ~2 anos.",
        "Quem enunciou a 'Lei de Moore', prevendo a duplicação\n"
        "de transistores a cada 2 anos?",
        {"Bill Gates", "Gordon Moore", "Jack Kilby", "Robert Noyce"},
        1
    },
    {
        "Era do Computador Pessoal", "1970 – 1980",
        "Altair 8800 e o Início do PC",
        "Em 1975, o Altair 8800 foi o primeiro microcomputador popular,\n"
        "vendido como kit por US$ 395. Bill Gates e Paul Allen\n"
        "escreveram um interpretador BASIC para ele e fundaram a\n"
        "Microsoft. Em 1977, Apple II, TRS-80 e Commodore PET\n"
        "popularizaram os computadores pessoais.",
        "Em que ano a Apple lançou o Macintosh,\n"
        "popularizando a interface gráfica (GUI)?",
        {"1981", "1984", "1986", "1979"},
        1
    },
    {
        "A Internet", "1969 – 1991",
        "De ARPANET à World Wide Web",
        "A ARPANET (1969) conectou 4 universidades americanas e foi a\n"
        "semente da internet. Em 1991, Tim Berners-Lee inventou a\n"
        "World Wide Web no CERN: URLs, HTML e HTTP. O primeiro site\n"
        "ainda está online: info.cern.ch.",
        "Onde Tim Berners-Lee trabalhava quando\n"
        "inventou a World Wide Web?",
        {"MIT", "Bell Labs", "CERN", "Stanford"},
        2
    },
    {
        "Era Moderna", "2000 – hoje",
        "Computação Quântica",
        "Computadores quânticos usam qubits, que podem ser 0, 1 ou\n"
        "ambos ao mesmo tempo (superposição). Em 2019, o Google\n"
        "afirmou atingir 'supremacia quântica': seu chip Sycamore\n"
        "resolveu em 200 segundos um problema que levaria 10.000 anos\n"
        "num supercomputador clássico.",
        "Qual é a propriedade quântica que permite a um qubit\n"
        "ser 0 e 1 simultaneamente?",
        {"Entrelaçamento", "Decoerência", "Superposição", "Tunelamento"},
        2
    }
};

const Color ERA_COLORS[MAX_QUESTIONS] = {
    {139, 90,  43,  255},  // marrom    – Era Mecânica
    {180, 60, 100,  255},  // rosa esc. – Primeira Programadora
    { 30, 90, 160,  255},  // azul      – Era Eletromecânica
    {180, 80,  20,  255},  // laranja   – ENIAC
    { 40,130,  60,  255},  // verde     – Transistor
    {100, 40, 160,  255},  // roxo      – Era do PC
    { 20,120, 140,  255},  // ciano     – Internet
    { 60, 60, 180,  255}   // azul esc. – Computação Quântica
};
