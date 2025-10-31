# Git 操作教学归档

以下内容归档自先前提供的 Git 教学与示例，涵盖基础配置、分支管理、远程协作、冲突解决等常见场景，便于后续查阅。

---

## 1. 初始配置与仓库创建

### 配置用户信息
```bash
git config --global user.name "你的用户名"
git config --global user.email "your_email@example.com"
```

### 创建新仓库
```bash
mkdir my-project
cd my-project
git init
```

### 查看状态
```bash
git status
```

---

## 2. 跟踪与提交更改

### 添加文件
```bash
git add README.md
git add src/  # 添加整个目录
git add .     # 添加当前目录所有修改
```

### 提交更改
```bash
git commit -m "添加 README 与基础结构"
```

### 查看提交历史
```bash
git log --oneline
git log --stat
git log --graph --oneline --decorate --all
```

---

## 3. 分支管理

### 创建与切换
```bash
git branch feature/login
git checkout feature/login        # Git < 2.23
git switch feature/login          # Git ≥ 2.23
git switch -c feature/login       # 创建并切换
```

### 合并分支
```bash
git checkout main
git merge feature/login
```

### 删除分支
```bash
git branch -d feature/login       # 合并后安全删除
git branch -D feature/login       # 强制删除
```

---

## 4. 远程仓库协作

### 添加远程
```bash
git remote add origin https://github.com/user/repo.git
```

### 推送代码
```bash
git push -u origin main
git push origin feature/login
```

### 拉取更新
```bash
git fetch origin
git pull origin main
```

### 克隆仓库
```bash
git clone https://github.com/user/repo.git
```

---

## 5. 解决冲突

当合并或拉取产生冲突时，Git 会标记冲突区域：
```
<<<<<<< HEAD
当前分支内容
=======
其他分支内容
>>>>>>> feature/login
```
手动编辑选择合适内容，然后：
```bash
git add 冲突的文件
git commit
```

---

## 6. 重写历史与回退

### 修改最后一次提交
```bash
git commit --amend
```

### 回退文件到暂存或某个版本
```bash
git checkout -- path/to/file       # 回退到最后一次提交
git checkout <commit> -- file      # 回退到指定提交版本
```

### 重置分支
```bash
git reset --soft HEAD~1   # 保留修改，撤销提交
git reset --mixed HEAD~1  # 撤销提交与暂存，保留工作区
git reset --hard HEAD~1   # 完全回退，不可恢复
```

---

## 7. 存储工作区（暂存工作目录）

```bash
git stash
git stash list
git stash pop
```

---

## 8. 打标签与发布

```bash
git tag v1.0.0
git push origin v1.0.0
```

---

## 9. 常用别名（提升效率）

```bash
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.cm "commit -m"
git config --global alias.lg "log --oneline --graph --decorate"
```

---

## 10. 多人协作最佳实践

1. **保持分支精简**：功能开发分支随用随建，完成后尽快合并或关闭。
2. **小步提交**：每次提交专注一个目的，配上清晰的提交信息。
3. **及时同步**：每天拉取最新的 `main`/`master` 分支并解决冲突，减少后期合并难度。
4. **代码评审**：使用 Pull Request 进行代码审查，保证质量与一致性。
5. **保持历史整洁**：PR 合并前可用 `git rebase` 或 `git squash` 整理提交（注意团队规范）。

---

## 11. 常见场景实战演示

### 11.1 新功能开发流程
```bash
# 基于 main 切新分支
git switch main
git pull origin main
git switch -c feature/payment

# 开发并提交
# (修改文件)
git status
git add src/payment.js
git commit -m "实现支付模块接口"

# 推送并提 PR
git push origin feature/payment
# 在远程仓库（GitHub/GitLab）发起 PR
```

### 11.2 修复热补丁
```bash
git switch main
git pull origin main
git switch -c hotfix/order-calc

# 修改并验证
git add order/calc.py
git commit -m "修复订单金额计算错误"

# 直接合并到 main
git switch main
git merge hotfix/order-calc
git push origin main
```

### 11.3 处理远程更新
```bash
# 在自己的功能分支
git switch feature/login
git fetch origin
git rebase origin/main   # 或 git merge origin/main

# 若有冲突，解决后继续
git add conflict-file
git rebase --continue

# 最终推送
git push origin feature/login --force-with-lease  # Rebase 后需强制推送
```

### 11.4 保存未完成工作
```bash
# 工作被打断
git status               # 有修改但不想提交
git stash                # 暂存

# 之后恢复
git stash pop
```

---

## 12. 资源推荐

- 《Pro Git》（免费电子书）
- 官方文档：<https://git-scm.com/docs>
- 图形化工具：GitKraken、Sourcetree、GitHub Desktop
- 学习平台：Codecademy、Udacity、Coursera 的 Git 课程

---

通过掌握这些操作，你可以流畅地在个人和团队项目中使用 Git 进行版本控制、协作开发、问题追踪以及发布部署。若需要更深入的场景（如 Git Flow、Monorepo 管理、CI/CD 集成等），可以在此基础上进一步扩展。
