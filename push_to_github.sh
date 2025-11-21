#!/bin/bash

# Chat项目备份脚本
echo "🔄 推送Chat项目到Freshman-Stage仓库..."
echo "时间: $(date)"

cd /home/kid/Projects/Chat

# 检查是否有文件变更
if git diff --quiet; then
    echo "ℹ️  代码无变更，无需备份"
else
    # 添加所有变更
    git add .
    
    # 提交变更
    git commit -m "Chat项目更新: $(date +"%Y-%m-%d %H:%M:%S")
    
项目状态: 
- 用户状态管理功能完整
- 智能指针内存安全
- 消息-用户状态一致性待解决
    
备份时间: $(date)"
    
    # 推送到GitHub的chat-project分支
    git push origin master:chat-project
    
    echo "✅ Chat项目备份完成！"
    echo "📌 分支: chat-project"
    echo "🌐 查看: https://github.com/KID-01/Freshman-Stage/tree/chat-project"
fi

echo "================================"
