document.addEventListener('DOMContentLoaded', function() {

    // <!-- ResetWeb -->
    if(document.querySelector('#valueResetWeb').value == '1'){
        document.querySelector('#resetForm').submit();
    }
    // <!-- StartWeb -->
    if(document.querySelector('#valueStartWeb').value == '1'){
        document.querySelector('#resetFormStartWeb').submit();
    }
    // <!-- InicioAdelanteWeb -->
    if(document.querySelector('#valueInicioAdelanteWeb').value == '1'){
        document.querySelector('#resetFormInicioAdelanteWeb').submit();
    }

    // <!-- StopWeb -->
    // if(document.querySelector('#valueStopWeb').value == '1'){
    //     document.querySelector('#resetFormStopWeb').submit();
    // }

    // <!-- InicioAtrasWeb -->
    if(document.querySelector('#valueInicioAtrasWeb').value == '1'){
        document.querySelector('#resetFormInicioAtrasWeb').submit();
    }
    // <!-- pasoAdelanteWeb -->
    document.querySelector('#submitPasoAdelanteWeb').addEventListener('mousedown', () => mouseDown());
    document.querySelector('#submitPasoAdelanteWeb').addEventListener('mouseup', () => mouseUp());

    // <!-- pasoAtrasWeb -->
    document.querySelector('#submitpasoAtrasWeb').addEventListener('mousedown', () => mouseDownAtras());
    document.querySelector('#submitpasoAtrasWeb').addEventListener('mouseup', () => mouseUpAtras());

});

function mouseDown(){
    document.querySelector('#formPasoAdelanteWeb').submit();
}

function mouseUp(){
    document.querySelector('#resetFormpasoAdelanteWeb').submit();
}

function mouseDownAtras(){
    document.querySelector('#formPasoAtrasWeb').submit();
}

function mouseUpAtras(){
    document.querySelector('#resetFormpasoAtrasWeb').submit();
}