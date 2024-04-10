// script.js
function preencherTabelaTransicao() {
    const form = document.getElementById('form-afd');
    const qtdEstados = parseInt(form['qtd-estados'].value);
    const qtdSimbolos = parseInt(form['qtd-simbolos'].value);

    let tabelaTransicaoHTML = '<h2>Tabela de Transição:</h2>';
    tabelaTransicaoHTML += '<table>';
    tabelaTransicaoHTML += '<tr><th>Estado</th>';
    for (let i = 0; i < qtdSimbolos; i++) {
        tabelaTransicaoHTML += `<th>${String.fromCharCode(97 + i)}</th>`;
    }
    tabelaTransicaoHTML += '</tr>';

    for (let i = 0; i < qtdEstados; i++) {
        tabelaTransicaoHTML += `<tr><td>q${i + 1}</td>`;
        for (let j = 0; j < qtdSimbolos; j++) {
            tabelaTransicaoHTML += `<td><input type="number" min="1" max="${qtdEstados}" name="tabela-${i}-${j}" required></td>`;
        }
        tabelaTransicaoHTML += '</tr>';
    }
    tabelaTransicaoHTML += '</table>';

    document.getElementById('tabela-transicao').innerHTML = tabelaTransicaoHTML;
}

function verificarPalavra() {
    const estadoInicial = parseInt(document.getElementById('estado-inicial').value);
    const estadosFinais = document.getElementById('estados-finais').value.split(',').map(Number);
    const palavra = document.getElementById('palavra').value;
    const qtdEstados = parseInt(document.getElementById('qtd-estados').value);
    const qtdSimbolos = parseInt(document.getElementById('qtd-simbolos').value);

    const tabelaTransicao = [];
    for (let i = 0; i < qtdEstados; i++) {
        const linha = [];
        for (let j = 0; j < qtdSimbolos; j++) {
            const input = document.getElementsByName(`tabela-${i}-${j}`)[0];
            linha.push(parseInt(input.value));
        }
        tabelaTransicao.push(linha);
    }

    let estadoAtual = estadoInicial;
    for (let i = 0; i < palavra.length; i++) {
        const indiceSimbolo = palavra.charCodeAt(i) - 97;
        estadoAtual = tabelaTransicao[estadoAtual - 1][indiceSimbolo];
    }

    const resultado = document.getElementById('resultado');
    if (estadosFinais.includes(estadoAtual)) {
        resultado.textContent = `A palavra "${palavra}" é aceita pelo AFD.`;
    } else {
        resultado.textContent = `A palavra "${palavra}" não é aceita pelo AFD.`;
    }
}
