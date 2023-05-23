document.addEventListener('DOMContentLoaded', function() {

    // <!-- ResetWeb -->
    if(document.querySelector('#valueResetWeb_2').value == '1'){
        document.querySelector('#resetForm_2').submit();
    }
    // <!-- StartWeb -->
    if(document.querySelector('#valueStartWeb_2').value == '1'){
        document.querySelector('#resetFormStartWeb_2').submit();
    }
    // <!-- InicioAdelanteWeb -->
    if(document.querySelector('#valueInicioAdelanteWeb_2').value == '1'){
        document.querySelector('#resetFormInicioAdelanteWeb_2').submit();
    }

    // <!-- StopWeb -->
    // if(document.querySelector('#valueStopWeb').value == '1'){
    //     document.querySelector('#resetFormStopWeb').submit();
    // }

    // <!-- InicioAtrasWeb -->
    if(document.querySelector('#valueInicioAtrasWeb_2').value == '1'){
        document.querySelector('#resetFormInicioAtrasWeb_2').submit();
    }
    // <!-- pasoAdelanteWeb -->
    document.querySelector('#submitPasoAdelanteWeb_2').addEventListener('mousedown', () => mouseDown_2());
    document.querySelector('#submitPasoAdelanteWeb_2').addEventListener('mouseup', () => mouseUp_2());

    // <!-- pasoAtrasWeb -->
    document.querySelector('#submitpasoAtrasWeb_2').addEventListener('mousedown', () => mouseDownAtras_2());
    document.querySelector('#submitpasoAtrasWeb_2').addEventListener('mouseup', () => mouseUpAtras_2());

});

function mouseDown_2(){
    document.querySelector('#formPasoAdelanteWeb_2').submit();
}

function mouseUp_2(){
    document.querySelector('#resetFormpasoAdelanteWeb_2').submit();
}

function mouseDownAtras_2(){
    document.querySelector('#formPasoAtrasWeb_2').submit();
}

function mouseUpAtras_2(){
    document.querySelector('#resetFormpasoAtrasWeb_2').submit();
}