var animationElements = document.querySelectorAll('.show-on-scroll')


function toogleAnimationElementInWindow(element) {
    console.log(element);
    var rect = element.getClientRects()[0]
    var heightScreen = window.innerHeight

    if (!(rect.bottom < 0 || rect.top > heightScreen)) {
        element.classList.add('start')
    } else {
        element.classList.remove('start')
    }

}


function checkAnimation() {
    animationElements.forEach(el => {
        toogleAnimationElementInWindow(el)

    })
}

window.onscroll = checkAnimation