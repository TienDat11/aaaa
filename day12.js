var process = document.querySelector('.process')
var range = document.querySelector('.range')
var value = document.querySelector('.process span')
var slider = document.getElementById('slider')
var body = document.querySelector('body')
var h1 = document.querySelector('h1')

function updateProcess(percent){
    process.style.width = `${percent}%`
    value.innerHTML = `${percent}%`
    body.style.background = `linear-gradient(to right, rgba(0,0,0,${percent/100}),rgba(0,0,0,${percent/100}))`

    if(percent < 20){
        h1.style.color = `black`
    }
    if(percent > 20 ){
        h1.style.color = `#fff`
    }

}

range.addEventListener('mousemove',function(e){
    var processWidth = e.pageX - this.offsetLeft
    var percent = processWidth / this.offsetWidth * 100 
    percent = Math.round(percent)
    updateProcess(percent)
})





