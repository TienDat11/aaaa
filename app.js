var images = document.querySelectorAll('.image img')
var prev = document.querySelector('.prev')
var next = document.querySelector('.right')
var close =  document.querySelector('.close')
var  galerryImg = document.querySelector('.galerry_inner img')
var galerry = document.querySelector('.galerry')

var currentIndex = 0;

function showgalerry(){
    if(currentIndex == 0){
        prev.classList.add('hide')
    }
    else{
        prev.classList.remove('hide')
    }
    galerryImg.src = images[currentIndex].src
    galerry.classList.add('show')
}

images.forEach((item, index)=>{
    item.addEventListener('click',function(){
        currentIndex = index
        showgalerry()
    })
})
close.addEventListener('click', function(){
    galerry.classList.remove('show')
})

document.addEventListener('keydown',function(e){
    if(e.keyCode == 27){
        galerry.classList.remove('show')
    }
})


prev.addEventListener('click',function(){
    if(currentIndex > 0 ){
        currentIndex--
        showgalerry()
    }

})

next.addEventListener('click',function(){
    if(currentIndex == 0 ){
        currentIndex++
        showgalerry()
    }
    else{
        currentIndex++
        showgalerry()
    }

})


document.onkeydown = function(event) {
    var e = event || window.event;
    if (e.keyCode == '37' && currentIndex >0) { //LEFT
      currentIndex--;
      showGalley();
    } else if (e.keyCode == '39' && currentIndex<7) { //RIGHT
      currentIndex++;
      showGalley();
    }
  }