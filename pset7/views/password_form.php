<form action="password.php" method="post">
    <fieldset>
        <div class="form-group">
            <input class="form-control" name="old" placeholder="Oldpassword" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="password" placeholder="New" type="password"/><!--placeholder  - Текст-подсказка в поле формы,-->
        </div>
        <div class="form-group">
            <input class="form-control" name="confirmation" placeholder="Submit" type="password"/><!--placeholder  - Текст-подсказка в поле формы,-->
        </div>

        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Submit
            </button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="login.php"> log in </a>
</div>
