const gulp = require("gulp");
const sass = require("gulp-sass");

gulp.task("scss", done => {
    gulp.src("resources/scss/*.scss")
        .pipe(sass({ outputStyle: "compressed" }).on("error", sass.logError))
        .pipe(gulp.dest("public/css/"));
    done();
});

gulp.task("watch", () => {
    gulp.watch("resources/scss/*.scss", gulp.parallel("scss"));
});
