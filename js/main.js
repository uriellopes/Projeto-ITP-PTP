var header = document.getElementById('header');

setInterval(function () {
    if (window.pageYOffset == 0) {
        header.classList.add('header');
        header.classList.remove('header-less');
    } else {
        header.classList.add('header-less');
        header.classList.remove('header');
    }
}, 50);