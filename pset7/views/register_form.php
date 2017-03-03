<form action="register.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="username" placeholder="Username" type="text"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="password" placeholder="Password" type="password"/><!--placeholder  - Текст-подсказка в поле формы,-->
        </div>
        <div class="form-group">
            <input class="form-control" name="confirmation" placeholder="Password" type="password"/><!--placeholder  - Текст-подсказка в поле формы,-->
        </div>

        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Registrer
            </button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="login.php"> log in </a>
</div>
