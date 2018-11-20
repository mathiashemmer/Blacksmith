# Main Idea:

Você é um blacksmither, um forjador de armas e armaduras, das mais mediocres até as mais épicas. Seu trabalho é ganhr dinheiro é claro! Para isso, será preciso adquirir matéria prima, e vender produtos processados para os aventureiros.

Todos os dias você deverá escolher entre algumas ações, como coletar recursos, criar armas, desenvolver novas tecnologias. Ao final de cada dia, você abre sua loja e os clientes irão comprar coisas. No inicio do próximo dia, você precisará gastar uma certa quantia em dinheiro para se manter vivo.

---

## Criando novos Itens:

Para criar um novo equipamento, selecione-o na aba de criação. um menu irá abrir, solicitando que cada parte seja preenchida com um material. A qualidade do material irá afetar a qualidade final do item, bem como sua eficiência em forja.

Todo item possui um número de materias nescessários, e os cálculos de valores e qualidade se baseiam nesses para se desenvolver.

### Custo do Item:

O custo base do ítem é calculado a partir da soma do custo do valor dos materiais, modificado pela qualidade final do item, somado a 25% do valor base (Isso garente que caso sua qualidade seja bad, não haverá muita perda de dinheiro). Cada material possui um valor de custo base, expresso na tabela:

| Material: | Custo Base |
| --------- | ---------- |
| wood      | 10         |
| Copper    | 15         |
| Iron      | 30         |
| Bronze    | 50         |
| Steel     | 100        |
| Gold      | 250        |

O custo final do item será o custo base multiplicado pelo fator de qualidade do item. 

### Qualidade do Item:

A qualidade do item é calculada a partir da qualidade de cada material, dependendo do número de materiais que vão na sua construção. Cada matéria prima possui uma qualidade específica, e um valor chave atribuido a ele, segundo a tabela:

| Qualidade do Material: | Valor: |
| ---------------------- | ------ |
| mixture                | 1      |
| impure                 | 2      |
| neutral                | 3      |
| purified               | 4      |
| pure                   | 5      |

A qualidade final do item é calculada a partir da soma dos valores chaves de cada item, baseando-se em um valor máximo,calculado dependendo da quantidade de matéria prima. Existem 7 qualidades de item, cada um possuindo um modificador de valor final, dado pela tabela:

| Qualidade do Item: | Modificador: |
| ------------------ | ------------ |
| bad                | 0.50         |
| usable             | 0.75         |
| common             | 1.00         |
| nice               | 1.25         |
| epic               | 1.50         |
| legendary          | 1.75         |
| titleworthy        | 2.00         |

Para calcular o valor da qualidade final, primeiro encontramos o maior valor possivel para a qualidade do item, caso seja utilizado somente ingredientes de qualidade pure
Uma situação hipotética, uma espada de uma mão:

Espada de uma Mão
* Total de Materiais: 3
* Qualidade máxima adquirida: 15 (3 * 5 = 15)

Então, soma-se a qualidade dos materias utilizados, e verifica-se qual a divergência do valor máximo. Se utilizar-se somente itens de qualidade neutral, teremos 3 * 3 = 9. Isso corresponde a 60% da qualidade máxima atingida. Pela próxima tabela, relaciona-se esse percentual ao valor da qualidade final:

| Percentual Atingido: | Qualidade:  |
| -------------------- | ----------- |
| < 40                 | bad         |
| 40 ~ 49              | usable      |
| 50 ~ 59              | common      |
| 60 ~ 69              | nice        |
| 70 ~ 79              | epic        |
| 80 ~ 89              | legendary   |
| > 90                 | titleworthy |

Nossa espada então, estaria entre 60 ~ 69, classificando ela com "nice", e adicionando um bonus de 1.25 de valor. Ainda é possivel que, dependendo da sua skill de forja, caso não tenha atingido os 100%, você ganhe um bonus em percentual. A chance depende de diversos fatores.

### Situação:

Se nossa espada for inteiramente feita de iron, teremos o seguinte calculo:

* Valor Base = (30 + 30 + 30) + ((30 + 30 + 30) * 0.25) = 113
* Qualidade = (3 + 3 + 3) * 100 / (5 + 5 + 5) = 60 -> "nice"
* Valor Final = 113 * 1.25 = 141.

