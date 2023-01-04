<?php include('server.php') ?>
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>LOGIN | HOSTEL MANAGMENT SYSTEM</title>
    <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
    <!-- <link rel="stylesheet" href="style.css"> -->
    <link rel="stylesheet" href="student-login.css">
    <script src="https://kit.fontawesome.com/830a36410b.js" crossorigin="anonymous"></script>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>

    <img src="student-bg.jpg" class="bg" alt="HOSTEL Image">

    <div class="wrapper">
      <div class="title-text">
        <div class="title login">Login</div>
        <div class="title signup">Login</div>
      </div>
      <div class="form-container">
        <div class="slide-controls">
          <input type="radio" name="slide" id="login" checked>
          <input type="radio" name="slide" id="signup">
          <label for="login" class="slide login">Student</label>
          <label for="signup" class="slide signup">Warden</label>
          <div class="slider-tab"></div>
        </div>
        <div class="form-inner">
          <form action="login.php" method="post" class="login">
            <?php include('errors.php'); ?>
            <div class="field">
              <input type="text" name="username" placeholder="Roll Number" required>
            </div>
            <div class="field">
              <input type="password" name="password" placeholder="Password" required>
            </div>
            <div class="field btn">
              <div class="btn-layer"></div>
              <input type="submit" value="Login" name="login_user">
            </div>
          </form>

          <form action="login.php" class="signup" method="post">
            <?php include('errors.php'); ?>
            <div class="field">
              <input type="text" name="username" placeholder="Hostel ID" required>
            </div>
            <div class="field">
              <input type="password" name="password" placeholder="Password" required>
            </div>
            <div class="field btn">
              <div class="btn-layer"></div>
              <input type="submit" value="Login" name="login_admin">
            </div>
          </form>
        </div>
      </div>
    </div>

    <script>
      const loginText = document.querySelector(".title-text .login");
      const loginForm = document.querySelector("form.login");
      const loginBtn = document.querySelector("label.login");
      const signupBtn = document.querySelector("label.signup");
      const signupLink = document.querySelector("form .signup-link a");
      signupBtn.onclick = (()=>{
        loginForm.style.marginLeft = "-50%";
        loginText.style.marginLeft = "-50%";
      });
      loginBtn.onclick = (()=>{
        loginForm.style.marginLeft = "0%";
        loginText.style.marginLeft = "0%";
      });
      signupLink.onclick = (()=>{
        signupBtn.click();
        return false;
      });
    </script>

  </body>
</html>
