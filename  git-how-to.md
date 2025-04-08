# SSH + GitHub Инструкция

```bash
# 1. Генерация SSH-ключа
ssh-keygen -t ed25519 -C "email@example.com"
# Нажимаем Enter 3 раза (без пароля)

# 2. Добавление ключа в GitHub
# Скопировать ключ:
cat ~/.ssh/id_ed25519.pub | pbcopy  # Mac
cat ~/.ssh/id_ed25519.pub | clip    # Windows
# Вставить на https://github.com/settings/keys

# 3. Клонирование репозитория 
git clone git@github.com:user/repo.git
cd repo

# 4. Проверка подключения
ssh -T git@github.com
# Должен показать ваш username