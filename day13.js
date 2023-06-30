const cancelBtn = document.querySelector('.cancel-btn');
const wrapper = document.querySelector('.wrapper');
const fileName = document.querySelector('.file-name');
const defaultBtn = document.querySelector('.default-btn');
const customBtn = document.querySelector('.custom-btn');
const img = document.querySelector('img');
let regExp = /[0-9a-zA-Z\^\&\'\@\{\}\[\]\,\$\=\!\-\#\(\)\.\%\+\~\_ ]+$/;
var error = document.querySelector('.error')
        function defaultBtnActive() {
            defaultBtn.click();
        }
        defaultBtn.addEventListener('change', function () {
            const file = this.files[0];

            if(!file)
                return


            if(!file.name.endsWith('.jpg')){
                error.innerHTML = 'Hinh anh khong phai thuoc dinh dang Jpeg'
                return
            }
            else{
                error.innerHTML =``
            }    
            if (file) {
                const reader = new FileReader();
                reader.onload = function () {
                    const result = reader.result;
                    img.src = result;
                    wrapper.classList.add("active");
                }
                cancelBtn.addEventListener('click', function () {
                    img.src = "";
                    wrapper.classList.remove("active");
                })
                reader.readAsDataURL(file);
            }
            if (this.value) {
                let valueStore = this.value.match(regExp);
                fileName.textContent = valueStore;
            }
        });