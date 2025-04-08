# Инструкции по работе с Git

## Как создать SSH ключ

```bash
ssh-keygen -t ed25519 -C "your_email@example.com"
```
(нажимаем Enter для всех вопросов)

## Как добавить ключ в аккаунт GitHub

1. Скопируйте содержимое публичного ключа:
   ```bash
   cat ~/.ssh/id_ed25519.pub
   ```
2. В GitHub перейдите в Settings → SSH and GPG keys
3. Нажмите "New SSH key"
4. Вставьте скопированный ключ и сохраните

## Как склонировать репозиторий

```bash
git clone git@github.com:username/repository.git
```