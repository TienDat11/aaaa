var username = document.querySelector('#username')
var email = document.querySelector('#email')
var password = document.querySelector('#password')
var confirmPassword = document.querySelector('#repassword')
var form = document.querySelector('form')


function showError(input,message){
    let parent = input.parentElement;
    let small = parent.querySelector('small')


    parent.classList.add('error')
    small.innerText= message
}


function showSucces(input){
    let parent = input.parentElement;
    let small = parent.querySelector('small')


    parent.classList.remove('error')
    small.innerText= ''
}

function checkEmptyError(listInput){
    let isEmtyError = false;
    listInput.forEach(input => {
        input.value = input.value.trim()
        if(!input.value){
            isEmtyError = true;
            showError(input,'Khong duoc de trong')
        }
        else{
            showSucces(input)
        }
    });
    return isEmtyError
}

function checkEmailError(input){
    const regexEmail = /[^\s@]+@[^\s@]+\.[^\s@]+/gi;
    input.value = input.value.trim()
    let isEmailError = !regexEmail.test(input.value)
    if(regexEmail.test(input.value)){
        showSucces(input)
    }
    else{
        showError(input,'Email Invalid')
    }
    return isEmailError
}

function checkLengthError(input,min,max){
    input.value = input.value.trim()

    if(input.value.length < min){
        showError(input,`Phai co it nhat ${min} ky tu`)
        return true
    }
    if(input.value.length > max ){
        showError(input, `Khong duoc qua ${max} ky tu`)
        return true
    }

    else{
        showSucces(input)
        return false
    }
}


function checkMatchPassword(passwordInput,cfPasswordInput){
    if(passwordInput.value != cfPasswordInput.value){
        showError(cfPasswordInput,'Mk khong trung khop')
        return true
    }
    return false
}

form.addEventListener('submit',function(e){
    e.preventDefault()
    let isEmtyError = checkEmptyError([username,email,password,confirmPassword])
    let isEmailError = checkEmailError(email)
    let isUsenameLengthError = checkLengthError(username,3,10)
    let isPasswordLengthError = checkLengthError(password,6,20)
    let isMatchError = checkMatchPassword(password,confirmPassword)

    if(isEmtyError || isEmailError || isUsenameLengthError || isPasswordLengthError ||isMatchError ){

    }
    else{
        
    }

    
})