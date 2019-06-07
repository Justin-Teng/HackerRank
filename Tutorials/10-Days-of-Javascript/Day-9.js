let r = document.getElementById("res");

function zero() {
    r.innerHTML += '0';
}

function one() {
    r.innerHTML += '1';
}

function clearResult() {
    r.innerHTML = '';
}

function add() {
    r.innerHTML += '+';
}

function subtract() {
    r.innerHTML += '-';
}

function multiply() {
    r.innerHTML += '*';
}

function divide() {
    r.innerHTML += '/';
}

function equal() {
    console.log('TETstestest');
    let res = r.innerHTML;
    
    let symbol = '';
    let symbolPos = res.indexOf('+');
    if (symbolPos == -1) {
        symbolPos = res.indexOf('-');
        if (symbolPos == -1) {
            symbolPos = res.indexOf('*');
            if (symbolPos == -1) {
                symbolPos = res.indexOf('/');
                symbol = '/';
            } else {
                symbol = '*';
            }
        } else {
            symbol = '-';
        }
    } else {
        symbol = '+';
    }
    
    let leftBin = res.substring(0, symbolPos);
    let rightBin = res.substring(symbolPos+1);
    let leftDec = parseInt(leftBin, 2);
    let rightDec = parseInt(rightBin, 2);
    
    let result = 0;
    if (symbol == '+')
        result = leftDec + rightDec;
    else if (symbol == '-')
        result = leftDec - rightDec;
    else if (symbol == '*')
        result = leftDec * rightDec;
    else
        result = parseInt(leftDec / rightDec);
    
    let resultBin = result.toString(2);
    r.innerHTML = resultBin;
}
