var header = document.getElementById('ul');

setInterval(function () {
    if (window.pageYOffset == 0) {
        ul.classList.add('navigation');
        ul.classList.remove('navigation-move');
    } else {
        ul.classList.add('navigation-move');
        ul.classList.remove('navigation');
    }
}, 50);
